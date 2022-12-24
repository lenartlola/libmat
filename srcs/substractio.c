//
// Created by Hajar on 24.12.22.
//

#include "libmat.h"

t_matrix	*substract_matrix(t_matrix *m1, t_matrix *m2) {
	int			rows;
	int			cols;
	t_matrix	*ret;

	if (m1->rows != m2->rows || m1->cols != m2->cols)
		return NULL;
	rows = m1->rows;
	cols = m1->cols;
	ret = init_matrix(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			ret->data[i][j] = m1->data[i][j] - m2->data[i][j];
		}
	}
	return ret;
}