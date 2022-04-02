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

	pid_t pid[PID_AMT_HASH] = {-1};
	int range_multipl = (int)HASH_RANGE / (int)PID_AMT_HASH;
	bool check_idf = false;
	unsigned short all_amt_idf = 0;

	for (int k = 0; k < PID_AMT_HASH; ++k) {
		pid[k] = fork();

		if (pid[k] == -1)
			printf("error, fork // get_idf\n");
		
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
					}
				check_idf = false;
				all_amt_idf = 0;
			}

			exit(k);
		}
		check_idf = false;
	}

	int status = 0;
	for (int k = 0; k < PID_AMT_HASH; ++k)
	{
		waitpid(pid[k], &status, 0);
		if (!WIFEXITED(status))
			printf("error, pid // get_idf\n");
	}

	return 1;
}