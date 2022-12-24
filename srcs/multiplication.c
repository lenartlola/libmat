//
// Created by Hajar on 24.12.22.
//

#include "libmat.h"

t_matrix	*multyply_matrix_by_matrix(t_matrix *m1, t_matrix *m2) {
	int			rows;
	int			cols;
	t_matrix	*ret;

	rows = m1->rows;
	cols = m2->cols;
	ret = init_matrix(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			int sum = 0;
			for (int k = 0; k < m1->cols; k++) {
				sum += m1->data[i][k] * m2->data[k][j];
			}
			ret->data[i][j] = sum;
		}
	}
	return ret;
}

t_matrix	*multiply_matrix_by_constant(t_matrix *matrix, int c) {
	int			rows;
	int			cols;
	t_matrix	*ret;

	rows = matrix->rows;
	cols = matrix->cols;
	ret = init_matrix(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			ret->data[i][j] = matrix->data[i][j] * c;
		}
	}
	return ret;
}

t_vector	*multiply_matrix_by_vector(t_matrix *matrix, t_vector *vec) {
	int			size;
	t_vector	*ret;

	size = vec->size;
	ret = init_vector(size);
	for (int i = 0; i < size; i++) {
		int sum = 0;
		for (int j = 0; j < matrix->cols; j++) {
			sum += matrix->data[i][j] * vec->data[j];
		}
		ret->data[i] = sum;
	}
	return ret;
}
