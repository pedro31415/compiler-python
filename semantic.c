#include "semantic.h"
#include <stdlib.h>
#include <string.h>

static Symbol *symbolTable = NULL;

void addSymbol(const char *name, const char *type) {
    Symbol *symbol = (Symbol*)malloc(sizeof(Symbol));
    symbol->name = strdup(name);
    symbol->type = strdup(type);
    symbol->next =  symbolTable;
    symbolTable = symbol;
}

int checkSymbol(const char *name) {
    Symbol *temp = symbolTable;
    while (temp) {
        if(strcmp(temp->name, name) == 0){
            return 1;
        } 
        temp = temp->next;
    }
}