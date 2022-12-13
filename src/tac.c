#include <stdio.h>
#include <string.h>
#include "tac.h"

int printTAC(FILE *fp, struct node_s *node, struct list *symbolTab){

    static int tempCounter = 0;
    int result = -1;

    if(node == NULL)
        return result;

    struct node_s *left = NULL;
    struct node_s *right = NULL;
    int leftTemp = -1;
    int rightTemp = -1;

    if(node->node_type == NODE_FUNC_DEF) {
        tempCounter = 0; // new context scope
        fprintf(fp, "// função: %s\n", node->child[1]->nodeName);
        fprintf(fp, "%s:\n", node->child[1]->nodeName);

        DEBUG_T("[#%d] %s:\n", __LINE__, node->child[1]->nodeName);
    }

    if(node->node_type == NODE_INT_TO_FLOAT){
        if(node->child[0]->node_type == NODE_INTEGER){
            result = tempCounter;
            fprintf(fp, "inttofl $%d, %d\n", tempCounter++, node->child[0]->integer);

            DEBUG_T("[#%d] inttofl $%d, %d\n", __LINE__, tempCounter, node->child[0]->integer);
            return result;
        } else {
            int resultExp = printTAC(fp, node->child[0], symbolTab);
            result = tempCounter;
            fprintf(fp, "inttofl $%d, $%d\n", tempCounter++, resultExp);

            DEBUG_T("[#%d] inttofl $%d, $%d\n", __LINE__, tempCounter, resultExp);
            return result;
        }

    } else if(node->node_type == NODE_FLOAT_TO_INT){
        if(node->child[0]->node_type == NODE_DECIMAL){
            result = tempCounter;
            fprintf(fp, "fltoint $%d, %f\n", tempCounter++, node->child[0]->decimal);

            DEBUG_T("[#%d] fltoint $%d, %f\n", __LINE__, tempCounter, node->child[0]->decimal);
            return result;
        } else {
            int resultExp = printTAC(fp, node->child[0], symbolTab);
            result = tempCounter;
            fprintf(fp, "fltoint $%d, $%d\n", tempCounter++, resultExp);

            DEBUG_T("[#%d] fltoint $%d, $%d\n", __LINE__, tempCounter, resultExp);
            return result;
        }
    }

    if(node->node_type == NODE_ASSIGN){

        if(node->child[1]->node_type == NODE_ID){
            fprintf(fp, "mov %s, %s\n", node->child[0]->nodeName, node->child[1]->nodeName);

            DEBUG_T("[#%d] mov %s, %s\n", __LINE__, node->child[0]->nodeName, node->child[1]->nodeName);
        } else if (node->child[1]->node_type == NODE_INTEGER){
            fprintf(fp, "mov %s, %d\n", node->child[0]->nodeName, node->child[1]->integer);

            DEBUG_T("[#%d] mov %s, %d\n", __LINE__, node->child[0]->nodeName, node->child[1]->integer);
        } else if(node->child[1]->node_type == NODE_DECIMAL) {
            fprintf(fp, "mov %s, %f\n", node->child[0]->nodeName, node->child[1]->decimal);

            DEBUG_T("[#%d] mov %s, %f\n", __LINE__, node->child[0]->nodeName, node->child[1]->decimal);
        } else if(node->child[1]->node_type == NODE_FACTOR){

            if (node->child[1]->child[0]->node_type == NODE_INTEGER){
                fprintf(fp, "mov %s, %d\n", node->child[0]->nodeName, node->child[1]->child[0]->integer);

                DEBUG_T("[#%d] mov %s, %d\n", __LINE__, node->child[0]->nodeName, node->child[1]->child[0]->integer);
            } else if(node->child[1]->child[0]->node_type == NODE_DECIMAL){
                fprintf(fp, "mov %s, %f\n", node->child[0]->nodeName, node->child[1]->child[0]->decimal);

                DEBUG_T("[#%d] mov %s, %f\n", __LINE__, node->child[0]->nodeName, node->child[1]->child[0]->decimal);
            } else {
                fprintf(fp, "mov %s, $%d\n", node->child[0]->nodeName, printTAC(fp, node->child[1], symbolTab));

                DEBUG_T("[#%d] mov %s, <>\n", __LINE__, node->child[0]->nodeName);
            }

        } else {
            int resultAssign = printTAC(fp, node->child[1], symbolTab);

            fprintf(fp, "mov %s, $%d\n", node->child[0]->nodeName, resultAssign);
            DEBUG_T("[#%d] mov %s, $%d\n", __LINE__, node->child[0]->nodeName, resultAssign);
        }

        return result;
    }

    if(node->node_type == NODE_WRITELN){

        if(node->child[0]->node_type == NODE_ID){
            fprintf(fp, "println %s\n", node->child[0]->nodeName);

            DEBUG_T("println %s\n", node->child[0]->nodeName);
        } else {
            DEBUG_T("[#%d] erro no fluxo\n", __LINE__);
        }

        return result;
    }

    if(node->node_type == NODE_ARITH_ADD
       || node->node_type == NODE_ARITH_SUB
       || node->node_type == NODE_ARITH_DIV
       || node->node_type == NODE_ARITH_MUL) {
        left = node->child[0];
        right = node->child[1];
    }

    if(left && left->node_type == NODE_FACTOR)
        left = left->child[0];

    if(right && right->node_type == NODE_FACTOR)
        right = right->child[0];

    if(left != NULL && (left->node_type == NODE_ARITH_ADD
        || left->node_type == NODE_ARITH_SUB
        || left->node_type == NODE_ARITH_DIV
        || left->node_type == NODE_ARITH_MUL))
        leftTemp = printTAC(fp, left, symbolTab);

    if(right != NULL && (right->node_type == NODE_ARITH_ADD
       || right->node_type == NODE_ARITH_SUB
       || right->node_type == NODE_ARITH_DIV
       || right->node_type == NODE_ARITH_MUL))
        rightTemp = printTAC(fp, right, symbolTab);

    if(left){
        if(left->node_type == NODE_INT_TO_FLOAT){
            if(left->child[0]->node_type == NODE_INTEGER){
                leftTemp = tempCounter;
                fprintf(fp, "inttofl $%d, %d\n", tempCounter++, left->child[0]->integer);

                DEBUG_T("[#%d] inttofl $%d, %d\n", __LINE__, tempCounter, left->child[0]->integer);
            } else if (left->child[0]->node_type == NODE_ID){
                leftTemp = tempCounter;
                fprintf(fp, "inttofl $%d, %s\n", tempCounter++, left->child[0]->nodeName);

                DEBUG_T("[#%d] inttofl $%d, %s\n", __LINE__, tempCounter, left->child[0]->nodeName);
            } else {
                DEBUG_T("[#%d] erro no fluxo\n", __LINE__);
            }
        } else if(left->node_type == NODE_FLOAT_TO_INT){
            if(left->child[0]->node_type == NODE_DECIMAL){
                leftTemp = tempCounter;
                fprintf(fp, "fltoint $%d, %f\n", tempCounter++, left->child[0]->decimal);

                DEBUG_T("[#%d] fltoint $%d, %f\n", __LINE__, tempCounter, left->child[0]->decimal);
            } else if (left->child[0]->node_type == NODE_ID){
                leftTemp = tempCounter;
                fprintf(fp, "fltoint $%d, %s\n", tempCounter++, left->child[0]->nodeName);

                DEBUG_T("[#%d] fltoint $%d, %s\n", __LINE__, tempCounter, left->child[0]->nodeName);
            } else {
                DEBUG_T("[#%d] erro no fluxo\n", __LINE__);
            }
        }
    }

    if(right){
        if(right->node_type == NODE_INT_TO_FLOAT){
            if(right->child[0]->node_type == NODE_INTEGER) {
                rightTemp = tempCounter;
                fprintf(fp, "inttofl $%d, %d\n", tempCounter++, right->child[0]->integer);

                DEBUG_T("[#%d] inttofl $%d, %d\n", __LINE__, tempCounter, right->child[0]->integer);
            } else if (right->child[0]->node_type == NODE_ID){
                rightTemp = tempCounter;
                fprintf(fp, "inttofl $%d, %s\n", tempCounter++, right->child[0]->nodeName);

                DEBUG_T("[#%d] inttofl $%d, %s\n", __LINE__, tempCounter, right->child[0]->nodeName);
            } else {
                DEBUG_T("[#%d] erro no fluxo\n", __LINE__);
            }
        } else if(right->node_type == NODE_FLOAT_TO_INT){
            if(right->child[0]->node_type == NODE_DECIMAL){
                rightTemp = tempCounter;
                fprintf(fp, "fltoint $%d, %f\n", tempCounter++, right->child[0]->decimal);

                DEBUG_T("[#%d] fltoint $%d, %f\n", __LINE__, tempCounter, right->child[0]->decimal);
            } else if (right->child[0]->node_type == NODE_ID){
                rightTemp = tempCounter;
                fprintf(fp, "fltoint $%d, %s\n", tempCounter++, right->child[0]->nodeName);

                DEBUG_T("[#%d] fltoint $%d, %s\n", __LINE__, tempCounter, right->child[0]->nodeName);
            } else {
                DEBUG_T("[#%d] erro no fluxo\n", __LINE__);
            }
        }
    }

    if(left != NULL && right != NULL) {

        if(node->node_type == NODE_ARITH_ADD){
            fprintf(fp, "add ");

            DEBUG_T("add ");
        } else if(node->node_type == NODE_ARITH_SUB){
            fprintf(fp, "sub ");

            DEBUG_T("sub ");
        } else if(node->node_type == NODE_ARITH_MUL){
            fprintf(fp, "mul ");

            DEBUG_T("mul ");
        } else if(node->node_type == NODE_ARITH_DIV){
            fprintf(fp, "div ");

            DEBUG_T("div ");
        } else{
            DEBUG_T("node_type nao implementado!\n");
        }

        if (left->node_type == NODE_INTEGER && right->node_type == NODE_INTEGER) {
            result = tempCounter;
            fprintf(fp, "$%d, %d, %d\n", tempCounter++, left->integer, right->integer);

            DEBUG_T("[#%d] $%d, %d, %d\n", __LINE__, result, left->integer, right->integer);
        } else if (left->node_type == NODE_DECIMAL && right->node_type == NODE_DECIMAL) {
            result = tempCounter;
            fprintf(fp, "$%d, %f, %f\n", tempCounter++, left->decimal, right->decimal);

            DEBUG_T("[#%d] $%d, %f, %f\n", __LINE__, result, left->decimal, right->decimal);
        } else {
            if (leftTemp != -1 && rightTemp != -1) {
                result = tempCounter;
                fprintf(fp, "$%d, $%d, $%d\n", tempCounter++, leftTemp, rightTemp);

                DEBUG_T("[#%d] $%d, $%d, $%d\n", __LINE__, result, leftTemp, rightTemp);
            } else if (left->node_type == NODE_INTEGER && rightTemp != -1) {
                result = tempCounter;
                fprintf(fp, "$%d, %d, $%d\n", tempCounter++, left->integer, rightTemp);

                DEBUG_T("[#%d] $%d, %d, $%d\n", __LINE__, result, left->integer, rightTemp);
            } else if (left->node_type == NODE_DECIMAL && rightTemp != -1) {
                result = tempCounter;
                fprintf(fp, "$%d, %f, $%d\n", tempCounter++, left->decimal, rightTemp);

                DEBUG_T("[#%d] $%d, %f, $%d\n", __LINE__, result, left->decimal, rightTemp);
            } else if (leftTemp != -1 && right->node_type == NODE_INTEGER){
                result = tempCounter;
                fprintf(fp, "$%d, $%d, %d\n", tempCounter++, leftTemp, right->integer);

                DEBUG_T("[#%d] $%d, $%d, %d\n", __LINE__, result, leftTemp, right->integer);
            } else if (leftTemp != -1 && right->node_type == NODE_DECIMAL){
                result = tempCounter;
                fprintf(fp, "$%d, $%d, %f\n", tempCounter++, leftTemp, right->decimal);

                DEBUG_T("[#%d] $%d, $%d, %f\n", __LINE__, result, leftTemp, right->decimal);
            } else {

                if(leftTemp == -1 && rightTemp == -1){
                    result = tempCounter;
                    fprintf(fp, "$%d, ", tempCounter++);

                    DEBUG_T("$%d, ", result);
                } else if ( leftTemp != -1 ) {
                    result = tempCounter;
                    fprintf(fp, "$%d, ", tempCounter++);
                    DEBUG_T("$%d, ", tempCounter);

                    fprintf(fp, "$%d, ", leftTemp);
                    DEBUG_T("$%d, ", leftTemp);
                    if(right->node_type == NODE_ID) {
                        fprintf(fp, "%s\n", right->nodeName);
                        DEBUG_T("%s\n", right->nodeName);
                    } else if(right->node_type == NODE_INTEGER) {
                        fprintf(fp, "%d\n", right->integer);
                        DEBUG_T("%d\n", right->integer);
                    } else if(right->node_type == NODE_DECIMAL) {
                        fprintf(fp, "%f\n", right->decimal);
                        DEBUG_T("%f\n", right->decimal);
                    } else {
                        int resultExp = printTAC(fp, right, symbolTab);

                        fprintf(fp, "$%d\n", resultExp);

                        DEBUG_T("$%d\n", resultExp);
                    }

                } else if( rightTemp != -1) {
                    result = tempCounter;
                    fprintf(fp, "$%d, ", tempCounter++);
                    DEBUG_T("$%d, ", tempCounter);

                    fprintf(fp, "$%d, ", rightTemp);
                    DEBUG_T("$%d, ", rightTemp);
                    if(left->node_type == NODE_ID) {
                        fprintf(fp, "%s\n", left->nodeName);
                        DEBUG_T("%s\n", left->nodeName);
                    } else if(left->node_type == NODE_INTEGER) {
                        fprintf(fp, "%d\n", left->integer);
                        DEBUG_T("%d\n", left->integer);
                    } else if(left->node_type == NODE_DECIMAL) {
                        fprintf(fp, "%f\n", left->decimal);
                        DEBUG_T("%f\n", left->decimal);
                    } else {
                        int resultExp = printTAC(fp, left, symbolTab);

                        if(resultExp == -1){
                            DEBUG_T("ops...\n");
                        }

                        fprintf(fp, "$%d\n", resultExp);

                        DEBUG_T("$%d\n", resultExp);
                    }

                } else {
                    DEBUG_T("[#%d] erro no fluxo\n", __LINE__);
                }
            }
        }

        return result;
    }

    for(int i = 0; i < node->numberChilds; ++i)
        result = printTAC(fp, node->child[i], symbolTab);

    return result;
}

void printTableTAC(FILE *fp, struct list *symbolTab){

    for (struct list *i = symbolTab; i; i = i->next) {

        switch (i->node->node_type) {
            case NODE_VAR_DECL:
                fprintf(fp, "%s %s", i->node->child[0]->nodeName, i->node->child[1]->nodeName);

                if(!strcmp(i->node->child[0]->nodeName, "int")){
                    fprintf(fp, " = 0");
                } else if (!strcmp(i->node->child[0]->nodeName, "float")){
                    fprintf(fp, " = 0.0f");
                }

                fprintf(fp, "\n");
                break;
            case NODE_FUNC_DEF:
            case NODE_PARAMETER:
                // nop
                break;
            default:
                DEBUG_T("[#%d] erro no fluxo\n", __LINE__);
        }
    }

}

void writeTAC(struct node_s *tree, struct list *symbolTab){
    FILE *fp = fopen("file.tac", "w");
    fprintf(fp, ".table\n");
    printTableTAC(fp, symbolTab);
    fprintf(fp, "\n.code\n");
    printTAC(fp, tree, symbolTab);
    fclose(fp);
}