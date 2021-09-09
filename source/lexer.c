#include "../headers/lexer.h"

struct scanner scanner;

static void nextSymbol() {
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
    case '\0':
        fclose( scanner.file );
        break;
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
    };
}

struct linked_symbol_list {
    struct symbol_node *head, *tail;
    unsigned int size;
};

struct symbol_node {
    char symbol;
    struct symbol_node *next;
};

static void insertLast( struct linked_symbol_list *linkedSymbolList, char symbol ) {
    struct symbol_node *node = malloc( sizeof( struct symbol_node ) );
    node->symbol = symbol;
    node->next = NULL;
    if( linkedSymbolList->size == 0 )
        linkedSymbolList->head = node, linkedSymbolList->tail = node;
    else
        linkedSymbolList->tail->next = node, linkedSymbolList->tail = node;
    linkedSymbolList->size++;
}

static void destroyLinkedSymbolList( struct linked_symbol_list *linkedSymbolList ) {
    struct symbol_node *node = linkedSymbolList->head;
    while( node != NULL ) {
        struct symbol_node *temp = node->next;
        free( node );
        node = temp;
    }
}

struct token nextToken() {
    unsigned int counter = 0;
    struct token token;
    return token;
}