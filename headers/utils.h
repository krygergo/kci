#ifndef KCI_UTILS_H
#define KCI_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <errno.h>

#define streq( s1, s2 ) strcmp( s1, s2 ) == 0 ? true : false

#endif // KCI_UTILS_H