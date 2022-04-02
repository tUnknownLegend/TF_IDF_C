#include "../include/struct.h"
#include "../include/def.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


int get_idf(my_idf* all_idf, int const amt_of_files) {

	bool check_idf = false;
	unsigned short all_amt_idf = 0;

	for (int i = 0; i < HASH_RANGE; ++i) {
		for (int j = 0; j < amt_of_files; ++j)
			if (all_idf[i].amt[j]) {
				++all_amt_idf;
				check_idf = true;
			}
			
		if (check_idf)
			all_idf[i].idf = log(((double)amt_of_files / (double)all_amt_idf));
		
		check_idf = false;
		all_amt_idf = 0;
	}

	return 1;
}