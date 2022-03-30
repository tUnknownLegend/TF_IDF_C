#include "calc_hash.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define FILE_IN "../../files/pg000.txt"
#define SIZE_OF_BUFFER 100
#define SIZE_OF_WORD 30
#define ALLOC_SIZE_TF 65534

struct tf {
	unsigned char str[SIZE_OF_WORD];
	unsigned long hash;
	unsigned short amt;
} my_tf_def = {"-", 0, 0};

typedef struct tf my_tf;

//my_tf* new_my_tf(char* const input_name, my_time* input_length, int const input_BPM) {

int main() {
	unsigned char buffer[SIZE_OF_WORD] = "-";
	FILE* in_file = NULL;
	FILE* out_file = stdout;
	FILE* err_file = stderr;

	if ((in_file = fopen(FILE_IN, "r")) == NULL) {
		fprintf(err_file, "Failed to open file\n");
	}
	/*
	while (!feof(in_file)) {
		if (fread(&buffer, sizeof(char), SIZE_OF_BUFFER - 1, in_file) > 0)
			printf("%s\n", buffer);
	}
	*/

	my_tf* tf_rec = calloc((ALLOC_SIZE_TF), sizeof(my_tf));
	if (tf_rec == NULL)
		fprintf(err_file, "Memory not allocated\n");		

	unsigned int curr_hash = 0;

	while (fscanf(in_file, "%29[a-zA-Z]", buffer) == 1) { // fix for large words is needed
		buffer[0] = tolower(buffer[0]);
		curr_hash = calc_hash(buffer); //fix
		memcpy(tf_rec[curr_hash].str, buffer, SIZE_OF_WORD);
		tf_rec[curr_hash].amt += 1;
    	//fprintf(out_file, "%s ", tf_rec[curr_hash].str);
    	fscanf(in_file, "%*[^a-zA-Z]");
	}

	for (int i = 0; i < ALLOC_SIZE_TF; ++i) {

		if (tf_rec[i].amt > 0)
    		fprintf(out_file, "word: %s; amount: %d\n", tf_rec[i].str, tf_rec[i].amt);
	}


	//printf("\n\n%s\n", buffer);

	if (fclose(in_file) != 0)
		fprintf(err_file, "Files isn't closed\n");		
	free(tf_rec);




	return 0;
}
