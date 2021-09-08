#include "../headers/interpreter.h"

static int build( struct iparam iparam ) {
    return 0;
}

static int clean( int exitcode, struct iparam iparam ) {
    return 0;
}

static bool iscfile( char cfile[] ) {
    size_t filelen = strlen( cfile );
    if( filelen > 1 && ( cfile[ filelen - 2] == '.' && cfile[ filelen - 1 ] == 'c' ) )
        return true;
    else
        return false;
}

static int run1( int argc, char *argv[] ) {
    struct iparam iparam = {};
    for( int i = 1; i < argc; i++ ) {
        if( iscfile( argv[i] ) ) {
            iparam.inputfile = fopen( argv[i], "r" );   
        }
    }
    return clean( build( iparam ), iparam );
}

static int run0() {
    return 0;
}

int run( int argc, char *argv[] ) {
    return argc == 1 ? run0() : run1( argc, argv );
}