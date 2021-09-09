#include "../headers/lexer.h"

struct scanner scanner;

void nextSymbol() {
    scanner.symbol = (char) fgetc( scanner.file );
    switch( scanner.symbol ) {
    case '\n':
        scanner.line++;
        scanner.row = 0;
        scanner.nextSymbol();
        break;
    case '\t':
        scanner.row += 4;
        scanner.nextSymbol();
        break;
    case ' ':
        scanner.row++;
        scanner.nextSymbol();
    default:
        scanner.row++;
        break;
    }
}

void initScanner( char *fileName ) {
    scanner = (struct scanner) {
        .file = fopen( fileName, "r" ),
        .line = 0,
        .row = 0,
        .nextSymbol = &nextSymbol
    }
}

enum token nextToken() {
    return ID;
}