#include "struct.h"
#include "def.h"
#include "get_metr.h"
#include "get_idf.h"
#include "get_tf_idf.h"
#include "tf_idf_top_5.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <errno.h>

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

// collision fix is needed
int main() {
	bool err = false;  //  error flag
	char buffer[SIZE_OF_WORD] = "-"; //  fix for large words is needed
	//FILE* const out_file = stdout;
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

	/* tf */

	char* temp_buf = malloc(sizeof(char) * (SIZE_OF_WORD + MAX(strlen(PATH_TO_FILES), strlen(PATH_TO_OUT_FILES))));  // fix for large words is needed
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
				//  getting path to open
				strcat(temp_buf, PATH_TO_FILES);
				strcat(temp_buf, buffer);
				temp_buf[strlen(PATH_TO_FILES) + strlen(buffer) - 1] = '\0';
				//fprintf(stdout, "%d // %s\n", i, temp_buf);

				//  open
				file_for_get = fopen(temp_buf, "r");
				if (file_for_get != NULL) {
					//  calc tf + precalculations for idf
					get_metr(tf_rec[i], all_idf, file_for_get, i);

					//  close
					if (fclose(file_for_get) != 0) {
						fprintf(err_file, "%s; fgets // file_for_get\n", strerror(errno));
						err = true;		
					}	
				} else {
					fprintf(err_file, "%s; fopen // file_for_get\n", strerror(errno));
					err = true;
				}

				temp_buf[0] = '\0';
			} else {
				fprintf(err_file, "%s; fgets // get names of files\n", strerror(errno));
				err = true;
				break;
			}
		}
	}

	//  close
	if (fclose(in_file_list) != 0) {
		fprintf(err_file, "%s; fclose // in_file_list\n", strerror(errno));
		err = true;		
	}

	/* end tf */

	/* idf + tf-idf */

	if (err == false) {
		bool check_idf[HASH_RANGE] = {false};
		int arr_ind[HASH_RANGE] = {0};

		//  calc idf
		get_idf(all_idf, check_idf, arr_ind, amt_of_files);
		//  calc tf_idf
		get_tf_idf(tf_rec, all_idf, amt_of_files);

		
		FILE* file_out = NULL;
		int top_5_ind[5] = {0};
		//file_out = fopen("../../files_report/res_out.txt", "a+");
		for (int i = 0; i < amt_of_files; ++i) {
			//  getting path to open
			buffer[0] = '\0';
			sprintf(buffer, "report_%d.txt", i);
			temp_buf[0] = '\0';
			strcat(temp_buf, PATH_TO_OUT_FILES);
			strcat(temp_buf, buffer);
			//fprintf(stdout, "%d // %s\n", i, temp_buf);

			//  open
			file_out = fopen(temp_buf, "a+");
			if (file_out != NULL) {
				//  top 5
				tf_idf_top_5(tf_rec[i], top_5_ind);
				fprintf(file_out, "TOP 5:\n");

				//  check if there at least then 5 TF-IDFs
				if (top_5_ind[0] >= 0)
					for (int k = 0; k < 5; ++k) {
						//printf("%d\n", top_5_ind[k]);
						fprintf(file_out, "word: %15s; TF: %f; IDF: %f; TF-IDF: %f\n", tf_rec[i][top_5_ind[k]].str, tf_rec[i][top_5_ind[k]].tf, all_idf[top_5_ind[k]].idf, tf_rec[i][top_5_ind[k]].tf_idf);
					}
				else 
					fprintf(file_out, "looks like there are no records\n");
				fprintf(file_out, "-------------------------------\n");

				for (int j = 0; j < HASH_RANGE; ++j) {
					if (tf_rec[i][j].amt > 0) {
    					fprintf(file_out, "word: %15s; TF: %f; IDF: %f; TF-IDF: %f\n", tf_rec[i][j].str, tf_rec[i][j].tf, all_idf[j].idf, tf_rec[i][j].tf_idf);			
					}
				}				

				//  close
				if (fclose(file_out) != 0) {
					fprintf(err_file, "%s; fgets // file_out\n", strerror(errno));
					err = true;		
				}		
				file_out = NULL;					

			} else {
				fprintf(err_file, "%s; fopen // file_out\n", strerror(errno));
				err = true;
			}					
		}			
	}

	free(temp_buf);
	temp_buf = NULL;

	/* end idf */

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

	return 0;
}
