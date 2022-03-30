#ifndef PROJECT_STRUCT_H_
#include <stdbool.h>
#include <stddef.h>
#define PROJECT_STRUCT_H_

struct tf {
	unsigned char* str; // fix? str[SIZE_OF_WORD]
	double tf;
	unsigned short amt;
} my_tf_def = {NULL, 0.0, 0};

typedef struct tf my_tf;

struct idf {
	double idf;
	bool* amt;
} my_idf_def = {0.0, NULL};

typedef struct idf my_idf;

#endif  //  PROJECT_STRUCT_H_
