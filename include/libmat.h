#ifndef LIBMAT_H
# define LIBMAT_H

#include <stdlib.h>

typedef struct s_matrix {
	int	rows;
	int	cols;
	int	**data;
}	t_matrix;

typedef struct s_vector {
	int	size;
	int *data;
}	t_vector;

// Matrix prototypes
t_matrix	*init_matrix(int rows, int cols);
void		fill_matrix(t_matrix *matrix, const int *array, int size);
void		destroy_matrix(t_matrix *matrix);
void		draw_matrix(t_matrix *matrix);

t_matrix	*add_matrix(t_matrix *m1, t_matrix *m2);
t_matrix	*substract_matrix(t_matrix *m1, t_matrix *m2);
t_matrix	*multyply_matrix_by_matrix(t_matrix *m1, t_matrix *m2);
t_matrix	*multiply_matrix_by_constant(t_matrix *matrix, int c);
t_matrix	*divide_matrix_by_matrix(t_matrix *m1, t_matrix *m2);
t_matrix	*negative_matrix(t_matrix *matrix);
t_matrix	*transpose_matrix(t_matrix *matrix);
t_matrix	*inverse_matrix(t_matrix *matrix);
t_matrix	*gaussian_elimination_matrix_inverse(t_matrix *m);


// Vector prototypes
t_vector	*init_vector(int size);

t_vector	*multiply_matrix_by_vector(t_matrix *matrix, t_vector *vec);

#endif //LIBMAT_H
