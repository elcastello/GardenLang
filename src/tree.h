#ifndef TREE_H_
#define TREE_H_

#define MAX_NODE_CHILD 10

#include <stdbool.h>

enum node_type {
    NODE_UNKNOWN,
    NODE_SCOPE,
    
    NODE_SOURCE,
    NODE_STMT_LIST,
    NODE_RETURN,
    NODE_FACTOR,

    NODE_ASSIGN,
    NODE_ADD_ASSIGN,
    NODE_SUB_ASSIGN,
    
    NODE_TYPE,
    NODE_CHAR,
    NODE_STRING,
    NODE_ID,
    NODE_INTEGER,
    NODE_DECIMAL,
    NODE_SET,
    NODE_ELEM,
    NODE_EMPTY,

    NODE_DECL_LIST,
    NODE_VAR_DECL,
    NODE_FUNC_DEF,
    NODE_CALL_FUNC,
    
    NODE_ARGS,
    NODE_PARAMS,
    NODE_PARAMETER,
    NODE_ARGUMENT,

    NODE_READ,
    NODE_WRITELN,
    NODE_WRITE,
    NODE_EXISTS,
    NODE_REMOVE,
    NODE_SET_ADD,
    NODE_IS_SET,
    NODE_SET_IN,

    NODE_COMP,
    NODE_NEG,
    NODE_OR,
    NODE_AND,
    NODE_COMP_OP,

    NODE_IF,
    NODE_ELSE,

    NODE_FOR,
    NODE_FORALL,

    NODE_ARITH_ADD,
    NODE_ARITH_SUB,
    NODE_ARITH_MUL,
    NODE_ARITH_DIV,

    NODE_INT_TO_FLOAT,
    NODE_FLOAT_TO_INT
};

struct node_s {
    int id;

    enum node_type node_type;

    int linha;
    int coluna;

    char *nodeName;

    union {
        int integer;
        double decimal;
    };

    struct list *pTable;

    struct node_s *escopo;

    int numberChilds;
    int maxNumberofChilds;
    struct node_s **child;

    unsigned int actualContext;
    unsigned int tempSlot;
};

struct node_s* createNode(enum node_type node_type, char *string);

void attachNode(struct node_s *parent, int children, ...);

void printCST(struct node_s *node, FILE *fp);
void writeCST(struct node_s *node);
void writeCSTConsole(struct node_s *node);

void printAST(struct node_s *node, FILE *fp);
void writeAST(struct node_s *node);
void writeASTConsole(struct node_s *node);

void applyParentAllChindren(struct node_s *parent, struct node_s *child);

void destroyTree(struct node_s *node);
void destroyNodeWithPtable(struct node_s *tree, struct list *pTable);

enum node_type strToType(char *type);
char *typeToStr(enum node_type nodeType);

bool isNodeToPrint(const struct node_s *node);

struct node_s *getLeftMostAt(struct node_s *tree, enum node_type nodeType, int position);

#endif