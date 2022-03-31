#include "../include/struct.h"
#include "../include/def.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


int get_idf(my_idf* all_idf, bool* check_idf, int* arr_ind, int const amt_of_files) {
	//  FILE* out_file = fopen("../logs/get_idf.log", "a+");
	//  FILE* err_file = stderr;

	unsigned short all_amt_idf = 0;
	// int arr_ind[HASH_RANGE] = {0};
	for (int i = 0; i < HASH_RANGE; ++i) {
		for (int j = 0; j < amt_of_files; ++j)
			if (all_idf[i].amt[j]) {
				++all_amt_idf;
				check_idf[i] = true;
				arr_ind[i] = j;
			}
		if (check_idf[i]) {
			all_idf[i].idf = log(((double)amt_of_files / (double)all_amt_idf));
			//fprintf(out_file, "%f; %d\n", all_idf[i].idf, all_amt_idf);
		}
		all_amt_idf = 0;
	}

	return 1;
}