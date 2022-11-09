#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdbool.h>

#include "main.h"
#include "tac.h"

extern FILE *yyin;
extern int lexicalErrors;

struct node_s *cst_root;
struct list *symbolTab;
struct list *dangledPointers;

int yylex_destroy();

int syntaxErrors = 0;
int semanticErrors = 0;

bool checkMainFunction(struct list *list) {
    bool result = false;
    for (struct list *i = list; i != NULL; i = i->next) {

        if (i->node != NULL && i->node->node_type == NODE_FUNC_DEF
            && !strcmp(i->node->child[1]->nodeName, "main")) {
            result = true;
            break;
        }

    }

    if (!result) {
        SERROR("Função main não declarada\n");
    }

    return result;
}

int main(int argc, char *argv[]) {

    symbolTab = createListNode(NODE_UNKNOWN);

    bool writeFile = false;

    if (argc > 1) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    for (int i = 0; i < argc; ++i) {
        if (!strcmp(argv[i], "--dotfile")) {
            writeFile = true;
            break;
        }
    }

    yyparse();

    checkMainFunction(symbolTab);

    checkSymbolDuplication(cst_root);
    semanticAnalysis(cst_root);

    if (!syntaxErrors && writeFile) {
        writeCST(cst_root);
    }

    if (!syntaxErrors) {
        writeASTConsole(cst_root);
//        writeCSTConsole(cst_root);
    }

    printTable(symbolTab);

    if (!syntaxErrors) {
        writeTAC(cst_root, symbolTab);
    }

    destroyTree(cst_root);

    destroyList(symbolTab);
    destroyList(dangledPointers);

    fclose(yyin);
    yylex_destroy();

    printf("\nErrors found: \n");
    printf("%-*s %d\n", 20, "- Lexical Errors:", lexicalErrors);
    printf("%-*s %d\n", 15, "- Syntatic Errors:", syntaxErrors);
    printf("%-*s %d\n", 15, "- Semantic Errors:", semanticErrors);

    return 0;
}

struct list *findSymbolOrInsert(struct node_s *node) {
    struct list *s = findSymbolByName(symbolTab, node);

    if (s == NULL) {
        s = insertSymbol(symbolTab, node);
    }

    return s;
}

enum node_type smtic_checkImplicitCast(struct node_s *tree) {
    if (tree == NULL)
        return NODE_UNKNOWN;

    if (tree->numberChilds > 0
        && (tree->child[0]->node_type == NODE_ARITH_ADD
            || tree->child[0]->node_type == NODE_ARITH_SUB
            || tree->child[0]->node_type == NODE_ARITH_MUL
            || tree->child[0]->node_type == NODE_ARITH_DIV)) {
        return smtic_checkImplicitCast(tree->child[0]);
    } else if (tree->node_type == NODE_FACTOR) {
        struct node_s *temp = tree;

        while (temp != NULL && temp->node_type == NODE_FACTOR) {
            if (temp->numberChilds > 0) {
                temp = temp->child[0];
            } else {
                break;
            }
        }

        if (temp != NULL && temp->numberChilds > 0
            && (temp->node_type == NODE_ARITH_ADD
                || temp->node_type == NODE_ARITH_SUB
                || temp->node_type == NODE_ARITH_MUL
                || temp->node_type == NODE_ARITH_DIV)) {
            return smtic_checkImplicitCast(temp->child[0]);
        } else {
            return temp->node_type;
        }
    }

    struct node_s *left = NULL;
    struct node_s *right = NULL;

    if (tree->node_type == NODE_CALL_FUNC) {
        struct list *s = findFunctionByName(symbolTab, tree->child[0]->nodeName);
        smtic_check_call_function(tree);
        return s != NULL ? strToType(s->node->child[0]->nodeName) : NODE_UNKNOWN;
    }

    if (tree->numberChilds > 0)
        left = tree->child[0];

    if (tree->numberChilds > 1)
        right = tree->child[1];

    enum node_type leftType = NODE_UNKNOWN;
    enum node_type rightType = NODE_UNKNOWN;

    if (left == NULL && right == NULL) {
        if (tree->node_type == NODE_ID) {
            struct list *s = findVariableByNameChangingScope(symbolTab, tree->nodeName, tree->escopo);
            return s != NULL ? strToType(s->node->child[0]->nodeName) : NODE_UNKNOWN;
        }

        return tree->node_type;
    }

    if (left != NULL) {
        if (left->node_type == NODE_ID) {
            struct list *s = findVariableByNameChangingScope(symbolTab, left->nodeName, left->escopo);
            leftType = s != NULL ? strToType(s->node->child[0]->nodeName) : NODE_UNKNOWN;
            if (s == NULL) {
                if (tree->node_type == NODE_CALL_FUNC) {
                    SERROR("Function [%s] not declared (%d, %d)\n", left->nodeName, left->linha, left->coluna);
                } else {
                    SERROR("Variable [%s] not declared (%d, %d)\n", left->nodeName, left->linha, left->coluna);
                }
            }
        } else if (left->node_type == NODE_CALL_FUNC) {
            smtic_check_call_function(left);
            struct list *s = findFunctionByName(symbolTab, left->child[0]->nodeName);
            leftType = s != NULL ? strToType(s->node->child[0]->nodeName) : NODE_UNKNOWN;
            if (s == NULL) {
                SERROR("Function [%s] not declared (%d, %d)\n", left->child[0]->nodeName, left->child[0]->linha,
                       left->child[0]->coluna);
            }
        } else {
            leftType = left->node_type;
        }
    }

    if (right != NULL) {
        if (right->node_type == NODE_ID) {
            struct list *s = findVariableByNameChangingScope(symbolTab, right->nodeName, right->escopo);
            rightType = s != NULL ? strToType(s->node->child[0]->nodeName) : NODE_UNKNOWN;
            if (s == NULL) {
                SERROR("Variable [%s] not declared (%d, %d)\n", right->nodeName, right->linha, right->coluna);
            }
        } else if (right->node_type == NODE_CALL_FUNC) {
            smtic_check_call_function(right);
            struct list *s = findFunctionByName(symbolTab, right->child[0]->nodeName);
            rightType = s != NULL ? strToType(s->node->child[0]->nodeName) : NODE_UNKNOWN;
            if (s == NULL) {
                SERROR("Function [%s] not declared (%d, %d)\n", right->child[0]->nodeName, right->child[0]->linha,
                       right->child[0]->coluna);
            }
        } else {
            rightType = right->node_type;
        }
    }

    enum node_type returnType = NODE_UNKNOWN;

    if (left && left->node_type == NODE_INT_TO_FLOAT)
        leftType = NODE_DECIMAL;

    if (right && right->node_type == NODE_INT_TO_FLOAT)
        rightType = NODE_DECIMAL;

    if (leftType == NODE_FACTOR && left->numberChilds == 1
        && !(left->child[0]->node_type == NODE_ARITH_ADD
             || left->child[0]->node_type == NODE_ARITH_SUB
             || left->child[0]->node_type == NODE_ARITH_MUL
             || left->child[0]->node_type == NODE_ARITH_DIV)) {
        leftType = left->child[0]->node_type;
    }

    if (rightType == NODE_FACTOR && right->numberChilds == 1
        && !(right->child[0]->node_type == NODE_ARITH_ADD
             || right->child[0]->node_type == NODE_ARITH_SUB
             || right->child[0]->node_type == NODE_ARITH_MUL
             || right->child[0]->node_type == NODE_ARITH_DIV)) {
        rightType = right->child[0]->node_type;
    }

    if (leftType == NODE_ARITH_ADD
        || leftType == NODE_ARITH_SUB
        || leftType == NODE_ARITH_MUL
        || leftType == NODE_ARITH_DIV
        || leftType == NODE_FACTOR) {
        leftType = smtic_checkImplicitCast(left);
    }

    if (rightType == NODE_ARITH_ADD
        || rightType == NODE_ARITH_SUB
        || rightType == NODE_ARITH_MUL
        || rightType == NODE_ARITH_DIV
        || rightType == NODE_FACTOR) {
        rightType = smtic_checkImplicitCast(right);
    }

    if (leftType != rightType) {
        if (leftType == NODE_INTEGER && rightType == NODE_DECIMAL) {
            struct node_s *new = createNode(NODE_INT_TO_FLOAT, "intToFloat");
            attachNode(new, 1, left);
            tree->child[0] = new;
            returnType = rightType;
        } else if (leftType == NODE_DECIMAL && rightType == NODE_INTEGER) {
            struct node_s *new = createNode(NODE_INT_TO_FLOAT, "intToFloat");
            attachNode(new, 1, right);
            tree->child[1] = new;
            returnType = leftType;
        } else {
            if (leftType != NODE_UNKNOWN && rightType != NODE_UNKNOWN) {
                printf("[ERRO] Conversion not defined for types: ");
                printf("[%s] e [%s]", typeToStr(leftType), typeToStr(rightType));
                printf("\n");
            }
        }
    } else if (leftType == NODE_SET || rightType == NODE_SET) {
        printf("[ERRO] Operation not defined for types: ");
        printf("[%s] e [%s]", typeToStr(leftType), typeToStr(rightType));
        printf("\n");
    } else {
        returnType = leftType;
    }

    return returnType;
}

bool findReturn(struct node_s *tree) {

    if (tree == NULL)
        return false;

    bool result = false;
    bool tempResult = false;
    struct node_s *upperScope = tree->escopo;

    if (tree->node_type == NODE_RETURN) {

        while (upperScope != NULL) {
            upperScope = upperScope->escopo;

            if (upperScope != NULL) {
                if (upperScope->node_type == NODE_IF
                    || upperScope->node_type == NODE_ELSE) {
                    return false;
                } else if (upperScope->node_type == NODE_FUNC_DEF) {
                    return true;
                }
            }
        }
    }

    for (int i = 0; i < tree->numberChilds; ++i) {
        tempResult = findReturn(tree->child[i]);

        if (!result) {
            result = tempResult;
        }
    }

    return result;
}

void smtic_checkReturnFunction(struct node_s *tree) {
    bool foundReturn = findReturn(tree);

    if (!foundReturn) {
        SWARNING("The function [%s] may not have a defined return type.\n", tree->child[1]->nodeName);
    }
}

void semanticAnalysis(struct node_s *tree) {

    if (tree == NULL || tree->nodeName == NULL)
        return;

    for (int i = 0; i < tree->numberChilds; ++i) {
        if (tree->child[i]->node_type == NODE_ASSIGN) {
            struct list *symbol = findVariableByNameChangingScope(symbolTab, tree->child[i]->child[0]->nodeName,
                                                     tree->child[i]->escopo);

            if (symbol != NULL && strToType(symbol->node->child[0]->nodeName) == NODE_SET
                && tree->child[i]->numberChilds > 1 && tree->child[i]->child[1]->node_type == NODE_EMPTY)
                continue;

            enum node_type result = smtic_checkImplicitCast(tree->child[i]->child[1]);
            enum node_type assignType = NODE_UNKNOWN;

            if (symbol != NULL && symbol->node != NULL && symbol->node->numberChilds > 0)
                assignType = strToType(symbol->node->child[0]->nodeName);

            if (result != assignType) {
                if (result == NODE_INTEGER && assignType == NODE_DECIMAL) {
                    struct node_s *new = createNode(NODE_INT_TO_FLOAT, "intToFloat");
                    attachNode(new, 1, tree->child[i]->child[1]);
                    tree->child[i]->child[1] = new;
                } else if (result == NODE_DECIMAL && assignType == NODE_INTEGER) {
                    struct node_s *new = createNode(NODE_FLOAT_TO_INT, "floatToInt");
                    attachNode(new, 1, tree->child[i]->child[1]);
                    tree->child[i]->child[1] = new;
                } else if (symbol != NULL && assignType != NODE_ELEM) {
                    SERROR("Cannot assign this type to variable [%s] (%d, %d)\n",
                           symbol->node->child[1]->nodeName,
                           tree->child[i]->child[0]->linha,
                           tree->child[i]->child[0]->coluna);
                } else if (symbol == NULL){
                    SERROR("The symbol [%s] is not defined or out of scope (%d, %d)\n",
                           tree->child[i]->child[0]->nodeName,
                           tree->child[i]->child[0]->linha,
                           tree->child[i]->child[0]->coluna);
                }
            }

        } else if (tree->child[i]->node_type == NODE_CALL_FUNC) {
            smtic_check_call_function(tree->child[i]);
        } else if (tree->child[i]->node_type == NODE_FUNC_DEF) {
            smtic_checkReturnFunction(tree->child[i]);
            semanticAnalysis(tree->child[i]);
        } else if (tree->child[i]->node_type == NODE_RETURN) {
            enum node_type returnType = smtic_checkImplicitCast(tree->child[i]->child[0]);

            if (returnType == NODE_UNKNOWN)
                returnType = tree->child[i]->child[0]->node_type;

            struct node_s *escopo = tree->child[i]->escopo;

            while (escopo != NULL && escopo->node_type != NODE_FUNC_DEF) {
                escopo = escopo->escopo;
            }

            enum node_type functionReturnType = strToType(escopo->child[0]->nodeName);
            if (functionReturnType != returnType) {
                if (functionReturnType == NODE_DECIMAL && returnType == NODE_INTEGER) {
                    struct node_s *new = createNode(NODE_INT_TO_FLOAT, "intToFloat");
                    attachNode(new, 1, tree->child[i]->child[1]);
                    tree->child[i]->child[1] = new;
                } else if (functionReturnType == NODE_INTEGER && returnType == NODE_DECIMAL) {
                    struct node_s *new = createNode(NODE_FLOAT_TO_INT, "floatToInt");
                    attachNode(new, 1, tree->child[i]->child[1]);
                    tree->child[i]->child[1] = new;
                } else {
                    SERROR("Cannot return this data type from the function [%s] (%d, %d)\n",
                           escopo->child[1]->nodeName,
                           escopo->child[0]->linha,
                           escopo->child[0]->coluna);
                }
            }
        } else {
            semanticAnalysis(tree->child[i]);
        }
    }
}

void smtic_check_call_function(struct node_s *func) {

    if (func == NULL || func->nodeName == NULL)
        return;

    struct list *s = findSymbolByName(symbolTab, func);
    struct node_s *formalParams = NULL;
    struct node_s *passedArgs = NULL;

    if (s != NULL && s->node != NULL
        && s->node->numberChilds > 2
        && ( s->node->child[2]->node_type == NODE_PARAMS
            || s->node->child[2]->node_type == NODE_PARAMETER)) {
        formalParams = s->node->child[2];
    }

    if (func->numberChilds > 0) {
        passedArgs = func->child[1];
    }

    int numParams = countNodeType(formalParams, NODE_PARAMETER);
    int numArgs = countNodeType(passedArgs, NODE_ARGUMENT);

    if (s != NULL && s->node != NULL && s->node->numberChilds > 1
        && numParams != numArgs) {
        SERROR("Function [%s] with incorrect number of arguments. Expected %d, Found %d. row %d column %d\n",
               s->node->child[1]->nodeName,
               numParams, numArgs,
               func->child[0]->linha, func->child[0]->coluna);
        return;
    }

    struct node_s *param = NULL;
    struct node_s *arg = NULL;
    int min = numParams > numArgs ? numArgs : numParams;
    for (int i = 0; i < min; ++i) {
        param = getLeftMostAt(formalParams, NODE_PARAMETER, i);
        arg = getLeftMostAt(passedArgs, NODE_ARGUMENT, i);

        enum node_type paramType = strToType(param->child[0]->nodeName);
        enum node_type argType = smtic_checkImplicitCast(arg->child[0]);

        if (arg->child[0]->node_type == NODE_ID) {

            struct list *temp = findVariableByNameChangingScope(symbolTab, arg->child[0]->nodeName, func->escopo);

            if (temp == NULL) {
                SERROR("Variable [%s] was not declared. (%d, %d)\n", arg->child[0]->nodeName,
                       arg->child[0]->linha, arg->child[0]->coluna);
            }

            if (temp != NULL && strcmp(temp->node->child[0]->nodeName, param->child[0]->nodeName) != 0) {
                SERROR("The parameter type in the position %d in the function [%s] is incorrect. Expected %s, found %s. (%d, %d)\n",
                       i, s->node->child[1]->nodeName,
                       param->child[0]->nodeName, temp->node->child[0]->nodeName,
                       arg->child[0]->linha, arg->child[0]->coluna);
            }
        } else if (argType == NODE_DECIMAL && paramType == NODE_INTEGER) {
            struct node_s *new = createNode(NODE_FLOAT_TO_INT, "floatToInt");
            attachNode(new, 1, arg->child[0]);
            arg->child[0] = new;
        } else if (argType == NODE_INTEGER && paramType == NODE_DECIMAL) {
            struct node_s *new = createNode(NODE_INT_TO_FLOAT, "intToFloat");
            attachNode(new, 1, arg->child[0]);
            arg->child[0] = new;
        } else {

            if (argType != paramType && paramType != NODE_ELEM) {
                SERROR("The parameter type in the position %d in the function [%s] is incorrect. Expected %s, found %s. (%d, %d)\n",
                       i, s->node->child[1]->nodeName, param->child[0]->nodeName, typeToStr(argType),
                       arg->child[0]->linha, arg->child[0]->coluna);
            }
        }
    }
}

int countNodeType(struct node_s *tree, enum node_type nodeType) {
    int times = 0;

    if (tree == NULL) {
        return 0;
    }

    if (tree->node_type == nodeType) {
        return 1;
    }

    for (int i = 0; i < tree->numberChilds; ++i) {
        times += countNodeType(tree->child[i], nodeType);
    }

    return times;
}

struct list *findSymbolSameScope(struct node_s *node) {

    if (!(node->node_type == NODE_VAR_DECL
          || node->node_type == NODE_FUNC_DEF
          || node->node_type == NODE_PARAMETER)) {
        return NULL;
    }

    bool foundYourself = false;

    for (struct list *i = symbolTab; i; i = i->next) {
        if (!foundYourself && i->node->id == node->id) {
            foundYourself = true;
        } else if (foundYourself && i->node->id != node->id
                   && !strcmp(i->node->child[1]->nodeName, node->child[1]->nodeName)
                   && i->node->escopo == node->escopo) {
            if((node->node_type == NODE_VAR_DECL || node->node_type == NODE_PARAMETER)
                && (i->node->node_type == NODE_VAR_DECL || i->node->node_type == NODE_PARAMETER)){
                SERROR("Symbol redeclaration [%s] (%d,%d)\n",
                       i->node->child[1]->nodeName, i->node->child[1]->linha, i->node->child[1]->coluna);
                return i;
            } else if (i->node->node_type == node->node_type) {
                SERROR("Symbol redeclaration [%s] (%d,%d)\n",
                       i->node->child[1]->nodeName, i->node->child[1]->linha, i->node->child[1]->coluna);
                return i;
            }
        }
    }

    return NULL;
}

void checkSymbolDuplication(struct node_s *node) {

    if (node == NULL) {
        return;
    }

    findSymbolSameScope(node);

    for (int i = 0; i < node->numberChilds; ++i) {
        checkSymbolDuplication(node->child[i]);
    }
}