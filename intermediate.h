#ifndef INTERMEDIATE_H
#define INTERMEDIATE_H

typedef struct  {
    char *result;
    char *arg1;
    char *op;
    char *arg2;
} TAC;

void generateTAC(const char *result, const char *args1, const char *op, const char *args2);

#endif