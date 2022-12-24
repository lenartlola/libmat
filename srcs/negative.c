//
// Created by Hajar on 24.12.22.
//

#include "libmat.h"

// Takes a struct of matrix as parameter and create a new negatived matrix
t_matrix	*negative_matrix(t_matrix *matrix) {
	int			rows;
	int			cols;
	t_matrix	*ret;

	rows = matrix->rows;
	cols = matrix->cols;
	ret = init_matrix(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			ret->data[i][j] = -matrix->data[i][j];
		}
	}
	return ret;
}