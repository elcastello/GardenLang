#ifndef TAC_H_
#define TAC_H_

#include "list.h"
#include "tree.h"

#ifdef DEBUG_TAC
#define DEBUG_T(...) printf(__VA_ARGS__)
#else
#define DEBUG_T(...)
#endif

int printTAC(FILE *fp, struct node_s *, struct list *);
void writeTAC(struct node_s *, struct list *);


#endif