//
// Created by Hajar on 24.12.22.
//

#include "libmat.h"

void	fill_matrix(t_matrix *matrix, const int *array, int size) {
	for (int i = 0; i< matrix->rows; i++) {
		for (int j = 0; j < matrix->cols; j++) {
			matrix->data[i][j] = array[i * matrix->cols + j];
		}
	}
}

void	fill_vector(t_vector *vec, const int *array, int size) {
	for (int i = 0; i < vec->size; i++) {
		vec->data[i] = array[i];
	}
}
