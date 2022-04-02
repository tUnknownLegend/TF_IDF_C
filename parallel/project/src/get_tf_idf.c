#include "../include/struct.h"
#include "../include/def.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int get_tf_idf(my_tf** tf_rec, my_idf const* const all_idf, int const amt_of_files) {

	pid_t* pid = mmap(NULL, sizeof(pid_t) * amt_of_files, PROT_READ | PROT_WRITE,
                               MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	if (pid == NULL)
		printf("error, calloc // get_tf_idf\n");

	for (int j = 0; j < amt_of_files; ++j) {
		pid[j] = fork();

		if (pid[j] == -1)
			printf("error, fork // get_tf_idf\n");

		if (pid[j] == 0) {

			for (int i = 0; i < HASH_RANGE; ++i) {

				if (tf_rec[j][i].amt > 0) {
					tf_rec[j][i].tf_idf = tf_rec[j][i].tf * all_idf[i].idf;
				}
			}

			exit(j);
		}
	}

	int status = 0;
	for (int k = 0; k < PID_AMT_HASH; ++k) {
		waitpid(pid[k], &status, 0);
		
		if (!WIFEXITED(status))
			printf("error, pid // get_tf_idf\n");
	}

	munmap(pid, sizeof(pid_t) * amt_of_files);

	return 1;
}
