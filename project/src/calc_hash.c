#include "../include/calc_hash.h"
#include <stdio.h>
/*
unsigned long sdbm(unsigned char *str)
    {
        unsigned long hash = 0;
        int c;
        while (c = *str++)
            hash = c + (hash << 6) + (hash << 16) - hash;

        return hash;
    }
    */

#define MAX_HASH 65534


unsigned long calc_hash(unsigned char *str) {
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return (hash % MAX_HASH);
}

/*
int main() {
    // Write C code here
                            //123456789012345678901234567890123
    unsigned long a = sdbm("Hrrrrrrrrrrrrrrrrrrrrrrgg");
    unsigned long b = hash("Hrrrrrrrrrrrrrrrrrrrrrrg11g1234234");
    
    printf("a: %d; b: %d", a, b);
    
    return 0;
}
*/