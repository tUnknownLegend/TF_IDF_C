#include "struct.h"
#include "def.h"
#include "get_metr.h"
#include "get_idf.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <errno.h>

/*
#define FILE_IN "../../files/pg000.txt"
#define FILE_IN_LIST "../../files/list_of_files.lll"
#define SIZE_OF_WORD 30
#define HASH_RANGE 65534

struct tf {
	unsigned char* str; // fix? str[SIZE_OF_WORD]
	double tf;
	unsigned short amt;
} my_tf_def = {NULL, 0.0, 0};

struct idf {
	double idf;
	bool* amt;
} my_idf_def = {0.0, NULL};

typedef struct tf my_tf;
typedef struct idf my_idf;
*/

// collision fix is needed
int main() {
	bool err = false;  //  error flag
	char buffer[SIZE_OF_WORD] = "-"; // fix for large words is needed
	FILE* const out_file = stdout;
	FILE* const err_file = stderr;
	FILE* const in_file_list = fopen(FILE_IN_LIST, "r");
	if (in_file_list == NULL) {
			fprintf(err_file, "%s; fopen // in_file_list\n", strerror(errno));
			err = true;
		}
	
	//  get amount of input files
	unsigned short amt_of_files = 0;
	if (fgets(buffer, SIZE_OF_WORD - 1, in_file_list) != NULL) {
		amt_of_files = strtol(buffer, NULL, 0);
		if (amt_of_files == 0) {
			fprintf(err_file, "%s; fgets // amt_of_files == 0\n", strerror(errno));
			err = true;
		}
	} else {
		fprintf(err_file, "%s; fgets // get amount of input files\n", strerror(errno));
		err = true;
	}

	//  alloc arr for idf
	my_idf* all_idf = calloc((HASH_RANGE), sizeof(my_idf));
	if (all_idf == NULL) {
		fprintf(err_file, "%s; calloc // all_idf\n", strerror(errno));
		err = true;
	}
	for (int i = 0; i < HASH_RANGE; ++i) {
		all_idf[i].amt = calloc((amt_of_files), sizeof(bool));
		if (all_idf[i].amt == NULL) {
			fprintf(err_file, "%s; calloc // all_idf[i].amt\n", strerror(errno));
			err = true;
		}
	}

	//  alloc arr for tf for each file
	my_tf** tf_rec = calloc((amt_of_files), sizeof(my_tf*));
	if (tf_rec == NULL) {
		fprintf(err_file, "%s; calloc // tf_rec\n", strerror(errno));
		err = true;
	}
	for (int i = 0; i < amt_of_files; ++i) {
		tf_rec[i] = calloc((HASH_RANGE), sizeof(my_tf));
		if (tf_rec[i] == NULL) {
			fprintf(err_file, "%s; calloc // my_tf[i]\n", strerror(errno));
			err = true;
		}
		for (int j = 0; j < HASH_RANGE; ++j) {
			tf_rec[i][j].str = malloc(sizeof(unsigned char) * (SIZE_OF_WORD));
			if (tf_rec[i][j].str == NULL) {
				fprintf(err_file, "%s; malloc // my_tf[i][j].str\n", strerror(errno));
				err = true;
			}
		}
	}	

	char* temp_buf = malloc(sizeof(char) * (SIZE_OF_WORD + strlen(PATH_TO_FILES)));  // fix for large words is needed
		if (temp_buf == NULL) {
			fprintf(err_file, "%s; malloc // temp_buf\n", strerror(errno));
			err = true;
		}
	temp_buf[0] = '\0';

	if (err == false) {
		FILE* file_for_get = NULL;
		//  get names of files
		for (int i = 0; i < amt_of_files; ++i) {  // amt_of_files
			if (fgets(buffer, SIZE_OF_WORD - 1, in_file_list) != NULL) {
				strcat(temp_buf, PATH_TO_FILES);
				strcat(temp_buf, buffer);
				temp_buf[strlen(PATH_TO_FILES) + strlen(buffer) - 1] = '\0';
				//fprintf(out_file, "%d // %s\n", i, temp_buf);
				file_for_get = fopen(temp_buf, "r");
				if (file_for_get == NULL) {
						fprintf(err_file, "%s; fopen // file_for_get\n", strerror(errno));
						err = true;
				} else {
					get_metr(tf_rec[i], all_idf, file_for_get, i);

					//  close
					if (fclose(file_for_get) != 0) {
						fprintf(err_file, "%s; fgets // file_for_get\n", strerror(errno));
						err = true;		
					}	
				}

				temp_buf[0] = '\0';
			} else {
				fprintf(err_file, "%s; fgets // get names of files\n", strerror(errno));
				err = true;
				break;
			}
		}
	}
	free(temp_buf);

	//  close
	if (fclose(in_file_list) != 0) {
		fprintf(err_file, "%s; fgets // in_file_list\n", strerror(errno));
		err = true;		
	}	

	/* idf */

	//bool check[HASH_RANGE] = {false};
	//bool* check_idf = calloc((HASH_RANGE), sizeof(bool));
	/*if (check_idf == NULL){
		fprintf(err_file, "%s; callocs // check_idf\n", strerror(errno));
		err = true;
	}*/

	if (err == false) {
		bool check_idf[HASH_RANGE] = {false};
		int arr_ind[HASH_RANGE] = {0};

		get_idf(all_idf, check_idf, arr_ind, amt_of_files);

		for (int i = 0; i < HASH_RANGE; ++i) {
			if (check_idf[i]) {
	    		fprintf(out_file, "word: %15s; TF: %f; IDF: %f; TF-IDF: %f\n", tf_rec[arr_ind[i]][i].str, tf_rec[arr_ind[i]][i].tf, all_idf[i].idf, tf_rec[arr_ind[i]][i].tf * all_idf[i].idf);			
			}
		}	
	}

	/* end idf */

	//  free
	for (int i = 0; i < HASH_RANGE; ++i)
		free(all_idf[i].amt);
	free (all_idf);

	for (int i = 0; i < amt_of_files; ++i) {
		for (int j = 0; j < HASH_RANGE; ++j)
			free(tf_rec[i][j].str);
		free(tf_rec[i]);
	}	
	free(tf_rec);

	return 0;
}
