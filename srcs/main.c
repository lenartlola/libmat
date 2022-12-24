//
// Created by Hajar on 24.12.22.
//

#include "libmat.h"
#include <stdio.h>

int	matrix_equal(t_matrix *m1, t_matrix *m2) {
	if (m1->rows != m2->rows || m1->cols != m2->cols)
		return 0;

	for (int i = 0; i < m1->rows; i++) {
		for (int j = 0; j < m1->cols; j++) {
			if (m1->data[i][j] != m2->data[i][j])
				return 0;
		}
	}
	return 1;
}

t_matrix	*identity_matrix(int size) {
	t_matrix	*res = init_matrix(size, size);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			res->data[i][j] = (i == j) ? 1 : 0;
		}
	}
	return res;
}

t_matrix	*cofactor_matrix(t_matrix *m, int row, int col) {
	t_matrix	*res = init_matrix(m->rows - 1, m->cols - 1);

	int row_index = 0;
	int col_index = 0;
	for (int i = 0; i < m->rows; i++) {
		if (i == row)
			continue;
		for (int j = 0; j < m->cols; j++) {
			if (j == col)
				continue;
			res->data[row_index][col_index] = m->data[i][j];
			col_index++;
		}
		row_index++;
		col_index = 0;
	}
	return res;
}

int	determinant(t_matrix *m) {
	if (m->rows != m->cols)
		return 0;

	if (m->rows == 1)
		return m->data[0][0];

	int det = 0;
	for (int i = 0; i < m->cols; i++) {
		int sign = (i % 2) ? -1 : 1;
		det += sign * m->data[0][i] * determinant(cofactor_matrix(m, 0, i));
	}
	return det;
}

void	test_gaussian_elimination_matrix_inverse(t_matrix *m) {
	if (m->rows != m->cols)
		return ;

	t_matrix	*inverse = gaussian_elimination_matrix_inverse(m);
	t_matrix	*identity = multyply_matrix_by_matrix(m, inverse);
	int			det_before = determinant(m);
	int			det_after = determinant(inverse);

	if (matrix_equal(identity, identity_matrix(m->rows)) &&
		det_before == det_after)
		printf("Test passed!\n");
	else
		printf("Test failed!\n");
}

int main(void) {
	t_matrix *m1;
	t_matrix *m2;

	m1 = init_matrix(2, 2);
	m2 = init_matrix(2, 2);
	int array1[4] = {3, 8, 4, 6};
	int array2[4] = {4, 0, 1, -9};
	fill_matrix(m1, array1, 4);
	fill_matrix(m2, array2, 4);
	draw_matrix(m1);
	draw_matrix(m2);

	printf("----------ADD----------\n");
	t_matrix *m_add = add_matrix(m1, m2);
	draw_matrix(m_add);
	destroy_matrix(m_add);

	printf("----------TRANSPOSITION----------\n");
	t_matrix *mt = init_matrix(2, 3);
	int t[6] = {6, 4, 24, 1, -9, 8};
	printf("----------Orig----------\n");
	fill_matrix(mt, t, 6);
	draw_matrix(mt);

	printf("----------Transposed----------\n");
	t_matrix *transposed = transpose_matrix(mt);
	draw_matrix(transposed);
	destroy_matrix(mt);
	destroy_matrix(transposed);

	printf("----------INVERSE----------\n");
	printf("Orig:\n");
	draw_matrix(m1);
	printf("Inverse:\n");
	test_gaussian_elimination_matrix_inverse(m1);

	destroy_matrix(m1);
	destroy_matrix(m2);
	return 0;
}