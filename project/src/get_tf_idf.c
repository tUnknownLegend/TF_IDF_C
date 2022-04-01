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
	//FILE* out_file = fopen("../logs/get_tf_idf.log", "a+");

	//pid_t pid[amt_of_files] = {-1};
	pid_t* pid = mmap(NULL, sizeof(pid_t) * amt_of_files, PROT_READ | PROT_WRITE,
                               MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	if (pid == NULL)
		printf("error, calloc // get_tf_idf\n");
	//int range_multipl = (int)HASH_RANGE / (int)PID_AMT_HASH;

	for (int j = 0; j < amt_of_files; ++j) {
	//for (int k = 0; k < PID_AMT_HASH; ++k) {//PID_AMT_HASH
		//printf("pre fork // %d\n", k);
		pid[j] = fork();
		if (pid[j] == -1)
			printf("error, fork // get_tf_idf\n");
		//printf("fork // %d\n", k);
		if (pid[j] == 0) {

			//for (int i = k * range_multipl; i < (k + 1) * range_multipl; ++i) {
			for (int i = 0; i < HASH_RANGE; ++i) {
				if (tf_rec[j][i].amt > 0) {
					tf_rec[j][i].tf_idf = tf_rec[j][i].tf * all_idf[i].idf;
					//fprintf(out_file, "word: %15s; TF: %f; IDF: %f; TF-IDF: %f\n",
					//	tf_rec[j][i].str, tf_rec[j][i].tf, all_idf[i].idf, tf_rec[j][i].tf_idf);
				}
			}
			exit(j);
		}
	}

	int status = 0;
	for (int k = 0; k < PID_AMT_HASH; ++k)
	{
		waitpid(pid[k], &status, 0);
		if (!WIFEXITED(status))
			printf("error, pid // get_tf_idf\n");
		//printf("exit code: %d // get_idf\n", WIFEXITED(status));
	}

	//fclose(out_file);

	//free(pid);
	munmap(pid, sizeof(pid_t) * amt_of_files);

	return 1;
}
