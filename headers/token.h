#ifndef KCI_TOKEN_H
#define KCI_TOKEN_H

enum token_type {
    ID,
    INT
};

struct token {
    enum token_type tokenType;
    char value[128];
};

char *keywords[] = {
    "if",
    "else"
};

#endif // KCI_TOKEN_H