#include "../include/calc_hash.h"
#include <stdio.h>

#define MAX_HASH 65534

unsigned long calc_hash(unsigned char *str) {
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return (hash % MAX_HASH);
}
