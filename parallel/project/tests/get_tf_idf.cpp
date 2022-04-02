#include <gtest/gtest.h>

extern "C" {
    #include "struct.h"
    #include "def.h"
    #include "calc_hash.h"
    #include "get_metr.h"
    #include "get_tf_idf.h"
    #include "get_idf.h"
    #include <stdbool.h>
    #include <stdio.h>
    #include <math.h>
}

TEST(get_tf_idf, 0)
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

    //  alloc arr for tf for each file
    my_tf** tf_rec = (my_tf**)calloc((amt_of_files), sizeof(my_tf*));
    if (tf_rec == NULL) {
        fprintf(err_file, "%s; calloc // tf_rec\n", strerror(errno));
    }
    for (int i = 0; i < amt_of_files; ++i) {
        tf_rec[i] = (my_tf*)calloc((HASH_RANGE), sizeof(my_tf));
        if (tf_rec[i] == NULL) {
            fprintf(err_file, "%s; calloc // my_tf[i]\n", strerror(errno));
        }
        for (int j = 0; j < HASH_RANGE; ++j) {
            tf_rec[i][j].str = (unsigned char*)malloc(sizeof(unsigned char) * (SIZE_OF_WORD));
            if (tf_rec[i][j].str == NULL) {
                fprintf(err_file, "%s; malloc // my_tf[i][j].str\n", strerror(errno));
            }
        }
    }

    FILE* input_file = fopen("../../tests/pg000.txt", "r");
    get_metr(tf_rec[0], all_idf, input_file, 0);

    unsigned char a[] = "file";
    unsigned char b[] = "gutenberg";
    unsigned int curr_hash1 = calc_hash(a);
    unsigned int curr_hash2 = calc_hash(b);

    get_idf(all_idf, amt_of_files);

    EXPECT_EQ(tf_rec[0][curr_hash1].tf_idf, 0);
    EXPECT_EQ(tf_rec[0][curr_hash2].tf_idf, 0);

    fclose(input_file);
    
    //  free
    for (int i = 0; i < HASH_RANGE; ++i){
        free(all_idf[i].amt);
        all_idf[i].amt = NULL;
    }
    free (all_idf);
    all_idf = NULL;

    for (int i = 0; i < amt_of_files; ++i) {
        for (int j = 0; j < HASH_RANGE; ++j){
            free(tf_rec[i][j].str);
            tf_rec[i][j].str = NULL;
        }
        free(tf_rec[i]);
        tf_rec[i] = NULL;
    }   
    free(tf_rec);
    tf_rec = NULL;
}