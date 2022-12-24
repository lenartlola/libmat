//
// Created by Hajar on 24.12.22.
//

#include "libmat.h"

//static t_matrix	*cofactor_matrix(t_matrix *matrix, int row, int col) {
//	int			row_i;
//	int			col_i;
//	t_matrix	*ret;
//
//	row_i = 0;
//	col_i = 0;
//	ret = init_matrix(matrix->rows - 1, matrix->cols - 1);
//	for (int i = 0; i < matrix->rows; i++) {
//		if (i == row)
//			continue;
//		for (int j = 0; j < matrix->cols; j++) {
//			if (i == col)
//				continue;
//			ret->data[row_i][col_i] = matrix->data[i][j];
//			col_i++;
//		}
//		row_i++;
//		col_i = 0;
//	}
//	return ret;
//}
//
//static int	determinant(t_matrix *matrix) {
//	int	det;
//	int	sign;
//
//	if (matrix->rows == 1)
//		return matrix->data[0][0];
//	det = 0;
//	for (int i = 0; i < matrix->cols; i++) {
//		// condition ? expression-true : expression-false
//		sign = (i % 2) ? -1: 1;
//		det += sign * matrix->data[0][i] * determinant(cofactor_matrix(matrix, 0, i));
//	}
//	return det;
//}
//
//t_matrix	*inverse_matrix(t_matrix *matrix) {
//	int			rows;
//	int			cols;
//	int			sign;
//	int			det;
//	int			cof;
//	t_matrix	*ret;
//
//	if (matrix->rows != matrix->cols)
//		return NULL;
//	rows = matrix->rows;
//	cols = matrix->cols;
//	ret = init_matrix(rows, cols);
//	det = determinant(matrix);
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cols; j++) {
//			sign = (i + j) % 2 ? -1: 1;
//			cof = sign * determinant(cofactor_matrix(matrix, i, j));
//			ret->data[j][i] = cof / det;
//		}
//	}
//	return ret;
//}

/*
 * The old approach doesn't work due to calculation on integers.
 * I'm using Gaussian Elimination algorithm to solve for the inverse of the matrix
 * The algorithm:
 		* Set up a coefficient matrix for the equations.
 		* Use row operations to convert the coefficient matrix into an upper triangular matrix.
 		* Perform back substitution to find the solution.
 * https://www.cmor-faculty.rice.edu/~zhang/caam335/F14/handouts/gaussian_elimination.pdf
*/

static t_matrix	*augment_matrix(t_matrix *matrix) {
	t_matrix	*ret;

	ret = init_matrix(matrix->rows, matrix->cols * 2);
	for (int i = 0; i < matrix->rows; i++) {
		for (int j = 0; j < matrix->cols; j++) {
			ret->data[i][j] = matrix->data[i][j];
			ret->data[i][j + matrix->cols] = (i == j) ? 1: 0;
		}
	}
	return ret;
}

static int	find_max_row(t_matrix *matrix, int col) {
	int	max;

	max = col;
	for (int i = col + 1; i < matrix->rows; i++) {
		if (abs(matrix->data[max][col]) < abs(matrix->data[i][col]))
			max = i;
	}
	return max;
}

static void	swap_rows(t_matrix *matrix, int r1, int r2) {
	int	tmp;

	if (r1 == r2)
		return;
	for (int i = 0; i < matrix->cols; i++) {
		tmp = matrix->data[r1][i];
		matrix->data[r1][i] = matrix->data[r2][i];
		matrix->data[r2][i] = tmp;
	}
}

t_matrix	*gaussian_elimination_matrix_inverse(t_matrix *matrix) {
	int			max_row;
	int			coef;
	t_matrix	*ret;
	t_matrix	*aug;

	if (matrix->rows != matrix->cols)
		return NULL;
	ret = init_matrix(matrix->rows, matrix->cols);
	aug = augment_matrix(matrix);
	for (int i = 0; i < matrix->rows; i++) {
		max_row = find_max_row(aug, i);
		if (aug->data[max_row][i] == 0)
			return NULL;
		swap_rows(aug, i, max_row);
		for (int j = 0; j < matrix->rows; j++) {
			if (i == j)
				continue;
			coef = aug->data[j][i] / aug->data[i][i];
			for (int k = 0; k < aug->cols; k++) {
				aug->data[j][k] -= aug->data[i][k] * coef;
			}
		}
	}
	for (int i = 0; i < matrix->rows; i++) {
		for (int j = 0; j < matrix->cols; j++) {
			ret->data[i][j] = aug->data[i][j + matrix->cols] / aug->data[i][i];
		}
	}
	destroy_matrix(aug);
	return ret;
}
