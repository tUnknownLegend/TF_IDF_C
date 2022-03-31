#include "../include/calc_hash.h"
#include "../include/struct.h"
#include "../include/def.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void get_lowercase(unsigned char* str) {
	for (int i = 0; str[i]; ++i)
		str[i] = tolower(str[i]);
}

int get_metr(my_tf* tf_rec, my_idf* all_idf, FILE* input_file, int file_ind) {
	unsigned char buffer[SIZE_OF_WORD] = "-";
	//  FILE* out_file = fopen("../logs/get_metr.log", "a+");

	unsigned int curr_hash = 0;
	unsigned int words_counter = 0;

	//  fprintf(out_file, "______________________________\n*START OF THE FILE %d*\n______________________________\n", file_ind);

   	fscanf(input_file, "%*[^a-zA-Z]");

	while (fscanf(input_file, "%29[a-zA-Z]", buffer) == 1) { // fix for large words is needed // %29[a-zA-Z]
		get_lowercase(buffer);
		curr_hash = calc_hash(buffer); //  fix?
		memcpy(tf_rec[curr_hash].str, buffer, SIZE_OF_WORD);

    	tf_rec[curr_hash].amt += 1;
    	++words_counter;

    	fscanf(input_file, "%*[^a-zA-Z]");

    	//  idf
    	all_idf[curr_hash].amt[file_ind] = true;
	}

	//  fprintf(out_file, "______________________________\ninput file: %d\n______________________________\n", file_ind);

	for (int i = 0; i < HASH_RANGE; ++i) {

		if (tf_rec[i].amt > 0) {
			tf_rec[i].tf = (double)tf_rec[i].amt / (double)words_counter;
    		//  fprintf(out_file, "word: %15s; amount: %3d; TF: %f\n", tf_rec[i].str, tf_rec[i].amt, tf_rec[i].tf);
		}
	}

	//  fprintf(out_file, "-------------------------------\namt of words: %d\n", words_counter);

	//  fclose(out_file);

	return 1;
}
