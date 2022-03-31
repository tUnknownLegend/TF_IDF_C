#include "../include/struct.h"
#include "../include/def.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int tf_idf_top_5(my_tf* tf_rec, int* top_5_ind) {
	FILE* out_file = fopen("../logs/tf_idf_top_5.log", "a+");
	
	double top_5_val[5] = {-1};

	//  getting first non zero elements ¯\_(ツ)_/¯ 
	int j = 0;
	for (int i = 0; i < HASH_RANGE && j < 5; ++i)
		if (tf_rec[i].amt > 0) {
			top_5_ind[j] = i;
			++j;
		}

	//  getting top 5 (ㆆ_ㆆ)
	for (int i = 0; i < HASH_RANGE; ++i) {
		if (tf_rec[i].tf_idf > top_5_val[4]) {

			if (tf_rec[i].tf_idf > top_5_val[3]) {

				if (tf_rec[i].tf_idf > top_5_val[2]) {

					if (tf_rec[i].tf_idf > top_5_val[1]) {

						if (tf_rec[i].tf_idf > top_5_val[0]) {
							top_5_val[0] = tf_rec[i].tf_idf;
							top_5_ind[0] = i;
							continue;
						}
						top_5_val[1] = tf_rec[i].tf_idf;
						top_5_ind[1] = i;
						continue;					
					}
					top_5_val[2] = tf_rec[i].tf_idf;
					top_5_ind[2] = i;
					continue;			
				}
				top_5_val[3] = tf_rec[i].tf_idf;
				top_5_ind[3] = i;
				continue;	
			}
			top_5_val[4] = tf_rec[i].tf_idf;
			top_5_ind[4] = i;
			continue;
		}
	}

	fclose(out_file);

	return 1;
}
