#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "tree.h"

struct list *createListNode() {
    struct list *s = (struct list *) calloc(1, sizeof(struct list));
    if (s == NULL) {
        printf("[#%d] Error: Symbol table could NOT be allocated!\n", __LINE__);
        return NULL;
    }

    s->node = NULL;
    s->next = NULL;
    return s;
}

struct list *insertSymbol(struct list *list, struct node_s *node) {

    if (list == NULL) {
        return NULL;
    }

    if (list->node == NULL) {
        list->node = node;

        return list;
    }

    struct list *prev = list;
    while (prev->next != NULL) {
        prev = prev->next;
    }

    struct list *newEntry = createListNode();
    newEntry->node = node;
    prev->next = newEntry;

    return newEntry;
}

struct list *findSymbolByName(struct list *list, struct node_s *node) {
    if( !list || !node )
        return NULL;

    if( !list->node && !list->next ){
        return NULL;
    }

    for(struct list *i = list; i != NULL; i = i->next) {

        if( i->node->node_type == NODE_FUNC_DEF
            && node->node_type == NODE_CALL_FUNC ) {

            if( !strcmp(i->node->child[1]->nodeName, node->child[0]->nodeName) ) {
                return i;
            }
        }
    }

    return NULL;
}

struct list *findStringOrChar(struct list *list, struct node_s *node){
     if( !list || !node )
        return insertSymbol(list, node);

     for(struct list *i = list; i != NULL; i = i->next) {

        if( i->node->node_type == NODE_STRING || i->node->node_type == NODE_CHAR) {
            if( !strcmp(i->node->child[1]->nodeName, node->child[0]->nodeName) ) {
                return i;
            }
        }
    }

    return NULL;
}

void printParameter(struct node_s *node){
    if(node == NULL)
        return;

    if (node->node_type == NODE_PARAMETER) {
        if(node->child[0] != NULL)
            printf("%s  ", node->child[0]->nodeName);

        if(node->child[1] != NULL)
            printf("%s  ", node->child[1]->nodeName);
    }


    for(int i = 0; i < node->numberChilds; ++i){
        printParameter(node->child[i]);
    }
}

void printTable(struct list *list) {
    unsigned int largura_coluna = 15;
    char header[] = "------------ Symbol Table ------------";

    printf("\n%s\n", header);
    printf("%-*s%-*s", largura_coluna, "TIPO", largura_coluna, "NOME");
    printf("%-*s%-*s%-*s", largura_coluna - 5, "LINHA", largura_coluna - 5, "COLUNA", largura_coluna, "INFO");
    printf("\n");

    if (list == NULL) {
        printf("Tabela vazia...\n");
    }

    struct node_s *node;
    for (struct list *i = list; i; i = i->next) {
        node = i->node;

        if(node == NULL)
            continue;

        printf("%-*s", largura_coluna, node->child[0]->nodeName);
        printf("%-*s", largura_coluna, node->child[1]->nodeName);
        printf("%-*d", largura_coluna - 5, node->child[1]->linha);
        printf("%-*d", largura_coluna - 5, node->child[1]->coluna);

        if (node->node_type == NODE_FUNC_DEF) {
            printf("%s, ", "função");

            printf("%s ( ", node->child[1]->nodeName);

            if(node->child[2]->node_type == NODE_PARAMS
                || node->child[2]->node_type == NODE_PARAMETER) {
                printParameter(node->child[2]);
            }

            printf(")");
        } else if (node->node_type == NODE_VAR_DECL) {

            printf("%s, ", "variável");
            printf("escopo: ");

            if ( node->escopo != NULL ) {

                if ( node->escopo->node_type == NODE_SCOPE ) {
                    printf("[id do escopo: %d]", node->escopo->id);
                }

            } else {
                printf("global");
            }
        } else if (node->node_type == NODE_PARAMETER){
            printf("%s, ", "parâmetro");

            if(node->escopo != NULL && node->escopo->numberChilds > 0) {
                printf("[id do escopo: %d]", node->escopo->id);
            }
        } else {
            printf("%-*s", largura_coluna, i->node->nodeName);
        }

        printf("\n");

    }

    for (int i = 0; i < strlen(header) - 1; ++i)
        printf("-");

    printf("\n");
}

void destroyList(struct list *list) {
    if (list == NULL) {
        return;
    }

    struct list *s;
    struct list *next = list;
    do {
        s = next;
        next = s->next;

        free(s);

    } while (next != NULL);
}

struct list *removeSymbol(struct list *list, struct list *symbol) {
    if (list == NULL || symbol == NULL)
        return NULL;

    struct list *prev;
    struct list *toDelete;

    for (struct list *i = list; i; i = i->next) {
        if (i->next == symbol) {
            prev = i;
            toDelete = i->next;
            break;
        }
    }

    prev->next = prev->next->next;

    toDelete->next = NULL;
    destroyList(toDelete);

    return NULL;
}

struct list *findVariableByName(struct list *list, char *name, struct node_s *escopo) {
    if( list == NULL || name == NULL )
        return NULL;

    for(struct list *i = list; i != NULL; i = i->next) {

        if( (i->node->node_type == NODE_VAR_DECL
            || i->node->node_type == NODE_PARAMETER)
            && i->node->escopo == escopo
            && !strcmp(i->node->child[1]->nodeName, name)){
            return i;
        }

    }

    return NULL;
}

struct list *findFunctionByName(struct list *list, char *name) {
    if( list == NULL || name == NULL )
        return NULL;

    for(struct list *i = list; i != NULL; i = i->next) {

        if( i->node->node_type == NODE_FUNC_DEF
            && !strcmp(i->node->child[1]->nodeName, name)){
            return i;
        }

    }

    return NULL;
}

struct list *findVariableByNameChangingScope(struct list *list, char *name, struct node_s *escopo) {
    // checar escopo
    struct node_s *upperScope = escopo;
    struct list *temp = findVariableByName(list, name, upperScope);

    if (temp == NULL) {
        while (upperScope != NULL) {
            upperScope = upperScope->escopo;
            temp = findVariableByName(list, name, upperScope);

            if (temp != NULL)
                break;
        }
    }

    return temp;
}

#if 0
int main(){
    struct list *lista = createListNode();
    append(lista, createNode("oi"));
    append(lista, createNode("oi2"));
    append(lista, createNode("oi3"));
    append(lista, createNode("oi4"));

    while(lista != NULL){
        printf("%s\n", lista->child->string);
        lista = nextAndDestroy(lista);
    }

}
#endif