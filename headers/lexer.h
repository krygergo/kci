#ifndef KCI_LEXER_H
#define KCI_LEXER_H

#include "utils.h"
#include "token.h"

struct scanner {
    FILE *file;
    char symbol;
    unsigned int line, row;
    void( *nextSymbol )();
};

extern struct scanner scanner;

void initScanner( char *fileName );
struct token nextToken();

#endif // KCI_LEXER_H