#include "lexer.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static const char *source;
static int pos = 0;
static int line = 1;
static int column = 1;

void initLexer(const char *input){
    source = input;
    pos = 0;
    line = 1;
    column = 1;
}

Token getToken() {
    Token token;
    token.lexeme[0] = '\0';
    token.type = T_END;  // Define um valor padrão para o token

    // Ignora espaços em branco
    while (isspace(source[pos])) {
        if (source[pos] == '\n') {
            line++;
            column = 1;
        } else {
            column++;
        }
        pos++;
    }

    // Verifica se chegou ao fim da entrada
    if (source[pos] == '\0') {
        token.type = T_END;
        return token;
    }

    // Identifica palavras-chave e identificadores
    if (isalpha(source[pos])) {
        int start = pos;
        while (isalnum(source[pos])) {
            pos++;
        }
        int len = pos - start;
        strncpy(token.lexeme, &source[start], len);
        token.lexeme[len] = '\0';

        // Verifica palavras-chave
        if (strcmp(token.lexeme, "if") == 0) {
            token.type = T_IF;
        } else if (strcmp(token.lexeme, "else") == 0) {
            token.type = T_ELSE;
        } else {
            token.type = T_INDENTIFIER;
        }
    } 
    // Verifica operadores (exemplo simples para '+')
    else if (source[pos] == '+') {
        token.type = T_OPERATOR;
        token.lexeme[0] = source[pos];
        token.lexeme[1] = '\0';
        pos++;
    }
    // Outros caracteres desconhecidos
    else {
        token.type = T_OPERATOR; // ou outro tipo que você preferir
        token.lexeme[0] = source[pos];
        token.lexeme[1] = '\0';
        pos++;
    }

    token.line = line;
    token.column = column;
    column++;
    
    return token;
}