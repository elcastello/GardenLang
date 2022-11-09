#ifndef LIST_H_
#define LIST_H_

#include "parser.tab.h"
#include "tree.h"

struct list {
    struct node_s *node;
    struct list *next;
};

struct list *createListNode();
struct list *insertSymbol(struct list *list, struct node_s *node);
struct list *findSymbolByName(struct list *list, struct node_s *node);
struct list *findSymbolOrInsertByName(struct list *list, struct node_s *node);

struct list *findVariableByName(struct list *list, char *name, struct node_s *escopo);
struct list *findVariableByNameChangingScope(struct list *list, char *name, struct node_s *escopo);
struct list *findFunctionByName(struct list *list, char *name);


struct list *removeSymbol(struct list *list, struct list *symbol);

void printTable(struct list *list);
void destroyList(struct list *list);

#endif