#include "../include/struct.h"
#include "../include/def.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int get_tf_idf(my_tf** tf_rec, my_idf const* const all_idf, int const amt_of_files) {

	for (int j = 0; j < amt_of_files; ++j)

		for (int i = 0; i < HASH_RANGE; ++i)

			if (tf_rec[j][i].amt > 0)
				tf_rec[j][i].tf_idf = tf_rec[j][i].tf * all_idf[i].idf;

	return 1;
}
