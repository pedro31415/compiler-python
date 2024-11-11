#ifndef LEXER_H
#define LEXER_H

typedef enum {
    T_IF, T_ELSE, T_WHILE, T_FOR, T_DEF, T_RETURN, 
    T_INDENTIFIER, T_NUMBER, T_OPERATOR, T_ASSIGN,
    T_LPAREN, T_RPAREN, T_LBRACE, T_END
} TokenType;

typedef struct  {
    TokenType type;
    char lexeme[64];
    int line;
    int column;
}Token;


Token getToken();
void initLexer(const char *input);

#endif

