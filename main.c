#include "lexer.h"
#include "parser.h"
#include "semantic.h"
#include "intermediate.h"
#include <stdio.h>

int main() {
    const char *sourceCode = "if x > 10: y = y + 2";

    initLexer(sourceCode);
    Token token;
    while ((token = getToken()).type != T_END) {
        printf("Token: %s (%d) at %d:%d\n", token.lexeme, token.type, token.line, token.column);
    }

    // Suponha que identificadores sejam variáveis
    addSymbol("x", "int");
    addSymbol("y", "int");

    // Geração de código intermediário
    generateTAC("y", "y", "+", "2");
    
    return 0;
}
