#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Token currentToken;

void advance() {
    currentToken = getToken();
}

Node* createNode(const char *type, const char *value) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->type = strdup(type);
    node->value = strdup(value);
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node* parseIfStatement() {
    advance();
    Node *node = createNode("IF_STATEMENT", "");

    advance();
    node->left = parseExpression();
    advance();
    node->right = parseExpression();

    return node;
}

Node* parseExpression() {
    Node *node = createNode("EXPRESSION", currentToken.lexeme);
    advance();
    return node;
}