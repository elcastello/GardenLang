#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "tree.h"
#include "list.h"
#include "parser.tab.h"

static int counter = 0;

extern struct list *dangledPointers;

void createEmpty(struct node_s *node) {
    node->nodeName = NULL;
    node->pTable = NULL;
    node->escopo = NULL;
    node->child = NULL;

    node->numberChilds = 0;
    node->maxNumberofChilds = MAX_NODE_CHILD;

    node->actualContext = 0;
    node->tempSlot = 0;
}

struct node_s *createNode(unsigned int node_type, char *string) {
    struct node_s *node = (struct node_s *) malloc(sizeof(struct node_s));
    createEmpty(node);

    node->id = counter++;
    node->node_type = node_type;
    node->nodeName = string;

    return node;
}

void destroyTree(struct node_s *node) {

    if (node == NULL) {
        return;
    }

    for (int i = 0; i < node->numberChilds; ++i) {

        if (node->child[i] == NULL)
            continue;

        if (node->child[i]->numberChilds != 0) {
            destroyTree(node->child[i]);
        } else {
            if (node->child[i]->node_type == NODE_COMP_OP
                || node->child[i]->node_type == NODE_CHAR
                || node->child[i]->node_type == NODE_STRING
                || node->child[i]->node_type == NODE_ID
                || node->child[i]->node_type == NODE_TYPE) {
                free(node->child[i]->nodeName);
            }

            free(node->child[i]);
        }

    }

    if (node->node_type == NODE_COMP_OP
        || node->node_type == NODE_CHAR
        || node->node_type == NODE_STRING
        || node->node_type == NODE_ID
        || node->node_type == NODE_TYPE) {
        free(node->nodeName);
    }

    if (node->child != NULL) {
        free(node->child);
    }

    free(node);
}

void printCST(struct node_s *node, FILE *fp) {
    if (node == NULL) {
        return;
    }

    switch (node->node_type) {
        case NODE_INTEGER:
            fprintf(fp, "%d [label=\"%d\"];\n", node->id, node->integer);
            break;
        case NODE_DECIMAL:
            fprintf(fp, "%d [label=\"%f\"];\n", node->id, node->decimal);
            break;
        default:
            fprintf(fp, "%d [label=\"%s\"];\n", node->id, node->nodeName);
    }

    for (int i = 0; i < node->numberChilds; ++i) {
        fprintf(fp, "%d -> %d ;\n", node->id, node->child[i]->id);

        printCST(node->child[i], fp);
    }
}

void printAST(struct node_s *node, FILE *fp){
//    if (node == NULL) {
//        return;
//    }
//
//    bool printNode = isNodeToPrint(node);
//
//    if(printNode) {
//        switch (node->node_type) {
//            case NODE_INTEGER:
//                fprintf(fp, "%d [label=\"%d\"];\n", node->id, node->integer);
//                break;
//            case NODE_DECIMAL:
//                fprintf(fp, "%d [label=\"%f\"];\n", node->id, node->decimal);
//                break;
//            default:
//                fprintf(fp, "%d [label=\"%s\"];\n", node->id, node->nodeName);
//        }
//    }
//
//    for (int i = 0; i < node->numberChilds; ++i) {
//        if(printNode) {
//            fprintf(fp, "%d -> %d ;\n", node->id, node->child[i]->id);
//        }
//
//        printAST(node->child[i], fp);
//    }
}

void writeAST(struct node_s *node) {
    FILE *fp = fopen("ast.dot", "w");

    if (fp == NULL) {
        printf("Error: Not possible to create the ast.dot file!\n");
        return;
    }

    fprintf(fp, "digraph tree {\n");
    printAST(node, fp);
    fprintf(fp, "}");

    fclose(fp);
}

void writeASTConsole(struct node_s *node) {
    printf("------- Abstract Syntax Tree -------\n");

    static unsigned int dash = 1;
    bool printNode = true;

    if (node == NULL) {
        return;
    }

    printNode = isNodeToPrint(node);

    if (printNode) {
        for (int j = 0; j < dash; ++j) {
            printf("-");
        }

        switch (node->node_type) {
            case NODE_INTEGER:
                printf("-> %d\n", node->integer);
                break;
            case NODE_DECIMAL:
                printf("-> %f\n", node->decimal);
                break;
            case NODE_SCOPE:
                printf("-> %s [id: %d]\n", node->nodeName, node->id);
                break;
            case NODE_ASSIGN:
                printf("-> %s\n", "=");
                break;
            case NODE_ARITH_ADD:
                printf("-> %s\n", "+");
                break;
            case NODE_ARITH_SUB:
                printf("-> %s\n", "-");
                break;
            case NODE_ARITH_MUL:
                printf("-> %s\n", "*");
                break;
            case NODE_ARITH_DIV:
                printf("-> %s\n", "/");
                break;
            case NODE_AND:
                printf("-> %s\n", "&&");
                break;
            case NODE_OR:
                printf("-> %s\n", "||");
                break;
            case NODE_NEG:
                printf("-> %s\n", "!");
                break;
            case NODE_COMP_OP:
                printf("-> %s\n", node->nodeName);
                break;
            default:
                printf("-> %s\n", node->nodeName);
        }
    }

    if (printNode) {
        dash += 3;
    }

    for (int i = 0; i < node->numberChilds; ++i) {
        writeASTConsole(node->child[i]);
    }

    if (printNode) {
        dash -= 3;
    }

    printf("----------------------\n");
}

bool isNodeToPrint(const struct node_s *node) {
    bool printNode = true;
    if (node->node_type == NODE_DECL_LIST
        || node->node_type == NODE_PARAMS
        || node->node_type == NODE_STMT_LIST
        || node->node_type == NODE_FACTOR
        || node->node_type == NODE_SET_IN
        || node->node_type == NODE_ARGS
        || node->node_type == NODE_COMP
        || node->node_type == NODE_ARGUMENT) {
        printNode = false;
    }
    return printNode;
}

void attachNode(struct node_s *parent, int children, ...) {

    if (parent->child == NULL) {
        parent->child = (struct node_s **) malloc(sizeof(struct node_s *) * MAX_NODE_CHILD);
    } else if ((parent->numberChilds + children) == parent->maxNumberofChilds) {
        struct node_s **newAlloc = (struct node_s **) realloc(parent->child,
                                                              ((parent->maxNumberofChilds + children) * 2) *
                                                              sizeof(struct node_s *));
        parent->child = newAlloc;
        parent->maxNumberofChilds = (parent->maxNumberofChilds + children) * 2;
    }

    struct node_s *child;
    va_list valist;
    va_start(valist, children);

    int index = parent->numberChilds;
    for (; index < (parent->numberChilds + children); ++index) {
        child = va_arg(valist, struct node_s *);
        parent->child[index] = child;
    }

    va_end(valist);
    parent->numberChilds = parent->numberChilds + children;
}

void destroyNodeWithPtable(struct node_s *tree, struct list *pTable) {
    if (tree == NULL)
        return;

    if (tree->node_type == NODE_VAR_DECL) {
        if (tree->pTable == pTable) {
            destroyTree(tree);
            return;
        }
    }

    for (int i = 0; i < tree->numberChilds; ++i) {
        destroyNodeWithPtable(tree->child[i], pTable);
    }
}

void applyParentAllChindren(struct node_s *parent, struct node_s *child) {
    if (child == NULL) {
        return;
    }

    if (child->escopo == NULL) {
        child->escopo = parent;
    }

    for (int i = 0; i < child->numberChilds; ++i) {
        applyParentAllChindren(parent, child->child[i]);
    }
}

void writeCST(struct node_s *node) {
    FILE *fp = fopen("ast.dot", "w");

    if (fp == NULL) {
        printf("Error: Not possible to create the ast.dot file!\n");
        return;
    }

    fprintf(fp, "digraph tree {\n");
    printCST(node, fp);
    fprintf(fp, "}");

    fclose(fp);
}

void writeCSTConsole(struct node_s *node) {
    printf("------- Concrete Syntax Tree -------\n");

    static unsigned int dash = 1;

    if (node == NULL) {
        return;
    }

    for (int j = 0; j < dash; ++j) {
        printf("-");
    }

    switch (node->node_type) {
        case NODE_INTEGER:
            printf("-> %d\n", node->integer);
            break;
        case NODE_DECIMAL:
            printf("-> %f\n", node->decimal);
            break;
        case NODE_FORALL:
        case NODE_IF:
        case NODE_ELSE:
        case NODE_FUNC_DEF:
        case NODE_SCOPE:
            printf("-> %s [id: %d]\n", node->nodeName, node->id);
            break;
        default:
            printf("-> %s\n", node->nodeName);
    }

    for (int i = 0; i < node->numberChilds; ++i) {
        dash += 3;
        writeCSTConsole(node->child[i]);
    }

    dash -= 3;
    printf("----------------------\n");
}

enum node_type strToType(char *type) {
    if (!strcmp(type, "int"))
        return NODE_INTEGER;
    else if (!strcmp(type, "float"))
        return NODE_DECIMAL;
    else if (!strcmp(type, "elem"))
        return NODE_ELEM;
    else if (!strcmp(type, "set"))
        return NODE_SET;
    else {
        printf("Data type not identified! Found: [%s]\n", type);
        return NODE_UNKNOWN;
    }
}

char *typeToStr(enum node_type nodeType) {
    switch (nodeType) {
        case NODE_INTEGER:
            return "int";
            break;
        case NODE_DECIMAL:
            return "float";
            break;
        case NODE_SET:
            return "set";
            break;
        case NODE_ELEM:
            return "elem";
            break;
        default:
            return "null";
    }
}

struct node_s *findLeftNodeExactTimes(struct node_s *tree, enum node_type nodeType, int position, int *tempCounter) {
    struct node_s *result;
    if (tree == NULL) {
        return 0;
    }

    if (tree->node_type == nodeType) {
        if (*tempCounter == position) {
            return tree;
        }

        *tempCounter = *tempCounter + 1;
    }

    for (int i = 0; i < tree->numberChilds; ++i) {
        result = findLeftNodeExactTimes(tree->child[i], nodeType, position, tempCounter);

        if (result != NULL)
            return result;
    }

    return NULL;
}

struct node_s *getLeftMostAt(struct node_s *tree, enum node_type nodeType, int position) {
    int times = 0;
    return findLeftNodeExactTimes(tree, nodeType, position, &times);
}

void reorganizeChildren(struct node_s *node) {
    int realChildren = 0;
    for (int i = 0; i < node->numberChilds; ++i) {
        if (node->child[i] != NULL) {
            ++realChildren;
        } else {
            node->child[i] = node->child[i + 1];
        }
    }

    node->numberChilds = realChildren;
}

#if 0
int main(){
    node *tree = createNode("src");
    addNode(tree, "if");
    addNode(tree, "(");
    node *exp = addNode(tree, "exp");
    addNode(exp, "2");
    addNode(exp, "+");
    addNode(exp, "5");
    addNode(exp, "5");
    addNode(exp, "5");
    addNode(exp, "5");
    addNode(exp, "5");
    addNode(exp, "5");
    addNode(exp, "5");
    addNode(exp, "5");
    addNode(exp, "5");
    addNode(exp, "5");
    addNode(exp, "5");
    addNode(exp, "5");
    addNode(exp, "5");
    addNode(exp, "5");
    addNode(exp, "5");
    addNode(exp, "5");
    addNode(exp, "5");
    addNode(exp, "5");
    addNode(exp, "5");
    addNode(exp, "5");
    addNode(exp, "5");
    addNode(exp, "5");
    addNode(exp, "5");
    addNode(exp, "5");

    addNode(tree, ")");
    addNode(tree, "{");
    addNode(tree, "stmt_group");
    addNode(tree, "}");

    writeTree(tree);

    destroyTree(tree);
}
#endif