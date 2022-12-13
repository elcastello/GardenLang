#ifndef MAIN_H_
#define MAIN_H_

#include "tree.h"
#include "list.h"

extern int semanticErrors;

#define SERROR(...) printf("[ERROR] " __VA_ARGS__); ++semanticErrors
#define SWARNING(...) printf("[WARNING] " __VA_ARGS__)

struct list *findSymbolOrInsert(struct node_s *node);

void semanticAnalysis(struct node_s *tree);
void smtic_check_call_function(struct node_s *func);
int countNodeType(struct node_s *tree, enum node_type nodeType);
enum node_type smtic_checkImplicitCast(struct node_s *tree);

void smtic_checkReturnFunction(struct node_s *tree);

void checkSymbolDuplication(struct node_s *node);
struct list *findSymbolSameScope(struct node_s *node);

#endif