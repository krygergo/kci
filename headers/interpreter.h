#ifndef KCI_INTERPRETER_H
#define KCI_INTERPRETER_H

#include "utils.h"

struct iparam {
    FILE *inputfile;
};

int run( int argc, char *argv[] );

#endif // KCI_INTERPRETER_H