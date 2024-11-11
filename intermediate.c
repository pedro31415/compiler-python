#include "intermediate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateTAC(const char *result, const char *arg1, const char *op, const char *arg2) {
    TAC *tac = (TAC*)malloc(sizeof(TAC));
    tac->result = strdup(result);
    tac->arg1 = strdup(arg1);
    tac->op = strdup(op);
    tac->arg2 = strdup(arg2);
    printf("%s = %s %s %s\n", result, arg1, op, arg2);
}
