#include "libmat.h"
#include <stdlib.h>

t_matrix	*init_matrix(int rows, int cols) {
		t_matrix	*matrix;

		matrix = (t_matrix*)malloc(sizeof(t_matrix));
		matrix->rows = rows;
		matrix->cols = cols;
		matrix->data = (int**)malloc(sizeof(int*) * rows);
		for (int i = 0; i < rows; i++) {
				matrix->data[i] = (int*)malloc(sizeof(int) * cols);
		}
		return matrix;
}

t_vector	*init_vector(int size) {
	t_vector	*vec = (t_vector*) malloc(sizeof(t_vector));

	vec->size = size;
	vec->data = (int*)malloc(sizeof(int) * size);
	return vec;
}
