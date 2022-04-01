#include <gtest/gtest.h>

extern "C" {
    #include "struct.h"
    #include "get_idf.h"
    
    #include "def.h"
    #include <stdbool.h>
    #include <stdio.h>
    #include <math.h>
}

TEST(get_idf, 0)
{
    FILE* const err_file = stderr;
    int const amt_of_files = 10;

    my_idf* all_idf = (my_idf*)calloc((HASH_RANGE), sizeof(my_idf));
    if (all_idf == NULL) {
        fprintf(err_file, "%s; calloc // all_idf\n", strerror(errno));
    }
    for (int i = 0; i < HASH_RANGE; ++i) {
        all_idf[i].amt = (bool*)calloc((amt_of_files), sizeof(bool));
        if (all_idf[i].amt == NULL) {
            fprintf(err_file, "%s; calloc // all_idf[i].amt\n", strerror(errno));
        }
    }


    all_idf[0].amt[0] = true;
    all_idf[0].amt[9] = true;
    for(int i = 0; i < 10; ++i)
        all_idf[3456].amt[i] = true;

    get_idf(all_idf, amt_of_files);

    EXPECT_EQ(all_idf[0].idf, log(double(10) / double(2)));
    EXPECT_EQ(all_idf[3456].idf, 0);

    for (int i = 0; i < HASH_RANGE; ++i){
        free(all_idf[i].amt);
        all_idf[i].amt = NULL;
    }
    free (all_idf);
    all_idf = NULL; 
}