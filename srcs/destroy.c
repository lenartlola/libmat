#include "libmat.h"
#include <stdlib.h>

void	destroy_matrix(t_matrix *matrix) {
	for (int i = 0; i < matrix->rows; i++) {
		free(matrix->data[i]);
		matrix->data[i] = NULL;
	}
	free(matrix->data);
	matrix->data = NULL;
	free(matrix);
	matrix = NULL;
}

void	destroy_vector(t_vector *vec) {
	free(vec->data);
	vec->data = NULL;
	free(vec);
	vec = NULL;
}
