//
// Created by Hajar on 24.12.22.
//

#include "libmat.h"
#include <stdio.h>

void	draw_matrix(t_matrix *matrix) {
	for (int i = 0; i < matrix->rows; i++) {
		for (int j = 0; j < matrix->cols; j++) {
			printf("%d ", matrix->data[i][j]);
		}
		printf("\n");
	}
}