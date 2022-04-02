#include "../include/def.h"
#include <stdio.h>

unsigned long calc_hash(unsigned char *str) {
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return (hash % HASH_RANGE);
}
