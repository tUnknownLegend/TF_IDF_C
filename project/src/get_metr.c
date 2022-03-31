#include "../include/calc_hash.h"
#include "../include/struct.h"
#include "../include/def.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int get_metr(my_tf* tf_rec, my_idf* all_idf, FILE* input_file, int file_ind) {
	unsigned char buffer[SIZE_OF_WORD] = "-";
	//unsigned char buff[SIZE_OF_WORD] = "-";
	FILE* out_file = fopen("../logs/get_metr.log", "a+");
	FILE* err_file = stderr;

	/*
	if ((input_file = fopen(input_file, "r")) == NULL) {
		fprintf(err_file, "Failed to open file\n");
	}
	*/

	unsigned int curr_hash = 0;
	unsigned int words_counter = 0;

	fprintf(out_file, "______________________________\n*START OF THE FILE %d*\n______________________________\n", file_ind);

   	fscanf(input_file, "%*[^a-zA-Z]");

    //  fscanf(input_file, "%29s", buffer);
    //  fprintf(out_file, "%s\n", buffer);

	while (fscanf(input_file, "%29[a-zA-Z]", buffer) == 1) { // fix for large words is needed // %29[a-zA-Z]
		//sscanf(buffer, "%29[a-zA-Z]", buff);
		//strcpy(buffer, buff);  //  FIX!
		buffer[0] = tolower(buffer[0]);  //  lowercase fix
		curr_hash = calc_hash(buffer); //  fix?
		//  fprintf(out_file, "hash: %d\n", curr_hash);
		memcpy(tf_rec[curr_hash].str, buffer, SIZE_OF_WORD);
		tf_rec[curr_hash].amt += 1;
		//  fprintf(out_file, "%s ", buffer);
    	//  fprintf(out_file, "%s ", tf_rec[curr_hash].str);
    	fscanf(input_file, "%*[^a-zA-Z]");
    	++words_counter;

    	//  idf
    	all_idf[curr_hash].amt[file_ind] = true;
	}

	//  fprintf(out_file, "______________________________\ninput file: %d\n______________________________\n", file_ind);

	for (int i = 0; i < HASH_RANGE; ++i) {

		if (tf_rec[i].amt > 0) {
			tf_rec[i].tf = (double)tf_rec[i].amt / (double)words_counter;
    		fprintf(out_file, "word: %15s; amount: %3d; TF: %f\n", tf_rec[i].str, tf_rec[i].amt, tf_rec[i].tf);
		}
	}

	fprintf(out_file, "-------------------------------\namt of words: %d\n", words_counter);

	fclose(out_file);

	return 1;
}