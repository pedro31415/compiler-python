#ifndef SEMANTIC_H
#define SEMANTIC_H

typedef struct Symbol {
    char *name;
    char *type;
    struct Symbol *next;
} Symbol;

void addSymbol(const char *name, const char *type);
int checkSymbol(const char *name);

#endif