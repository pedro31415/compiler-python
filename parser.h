#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

typedef struct Node {
    char *type;
    char *value;
    struct Node *left;
    struct Node *right;
} Node;

Node* parseExpression();
Node* parseIfStatement();

#endif