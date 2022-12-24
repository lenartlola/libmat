//
// Created by Hajar on 24.12.22.
//

#include "libmat.h"

// Takes a matrix as parameter and returns a pointer to a new transposed matrix
t_matrix	*transpose_matrix(t_matrix *matrix) {
	int			rows;
	int			cols;
	t_matrix	*ret;

	rows = matrix->rows;
	cols = matrix->cols;
	ret = init_matrix(cols, rows);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			ret->data[j][i] = matrix->data[i][j];
		}
	}
	return ret;
}
