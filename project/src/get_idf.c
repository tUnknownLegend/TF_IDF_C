#include "../include/struct.h"
#include "../include/def.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int get_idf(my_idf* all_idf, int const amt_of_files) {
	//  FILE* out_file = fopen("../logs/get_idf.log", "a+");
	//  FILE* err_file = stderr;

	pid_t pid[PID_AMT_HASH] = {-1};
	int range_multipl = (int)HASH_RANGE / (int)PID_AMT_HASH;
	bool check_idf = false;
	unsigned short all_amt_idf = 0;

	for (int k = 0; k < PID_AMT_HASH; ++k) {//PID_AMT_HASH
		printf("pre fork // %d\n", k);
		pid[k] = fork();
		if (pid[k] == -1)
			printf("error, fork // get_idf\n");
		printf("fork // %d\n", k);
		if (pid[k] == 0) {

			for (int i = k * range_multipl; i < (k + 1) * range_multipl; ++i) {

					for (int j = 0; j < amt_of_files; ++j)
						if (all_idf[i].amt[j]) {
							++all_amt_idf;
							check_idf = true;
							//arr_ind[i] = j;
						}

					if (check_idf) {
						all_idf[i].idf = log(((double)amt_of_files / (double)all_amt_idf));
						//  fprintf(out_file, "%f; %d\n", all_idf[i].idf, all_amt_idf);
					}
				check_idf = false;
				all_amt_idf = 0;
			}
/*
			for (int i = k * range_multipl; i < (k + 1) * range_multipl; ++i)
			{
				printf("in fork %d // %f\n", k, all_idf[i].idf);
			}
*/
			exit(k);
			//printf("HEYY // %d\n", k);
		}
	}
	//  fclose(out_file);
	int status = 0;
	for (int k = 0; k < PID_AMT_HASH; ++k)
	{
		waitpid(pid[k], &status, 0);
		if (!WIFEXITED(status))
			printf("error, pid // get_idf\n");
		printf("exit code: %d // get_idf\n", WIFEXITED(status));
	}

/*	for (int i = 0; i < (1) * range_multipl; ++i)
	{
		printf("out fork %d // %f\n", i, all_idf[i].idf);
	}
*/
	return 1;
}