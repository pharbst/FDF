/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:46:14 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/02 20:08:57 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static double	**ft_yaw(double **matrix, double angel)
{
	matrix[0][0] = cos(angel * (M_PI / 180));
	matrix[0][2] = -sin(angel * (M_PI / 180));
	matrix[2][0] = sin(angel * (M_PI / 180));
	matrix[2][2] = cos(angel * (M_PI / 180));
	return (matrix);
}

static double	**ft_pitch(double **matrix, double angel)
{
	matrix[1][1] = cos(angel * (M_PI / 180));
	matrix[1][2] = sin(angel * (M_PI / 180));
	matrix[2][1] = -sin(angel * (M_PI / 180));
	matrix[2][2] = cos(angel * (M_PI / 180));
	return (matrix);
}

static double	**ft_roll(double **matrix, double angel)
{
	matrix[0][0] = cos(angel * (M_PI / 180));
	matrix[0][1] = -sin(angel * (M_PI / 180));
	matrix[1][0] = sin(angel * (M_PI / 180));
	matrix[1][1] = cos(angel * (M_PI / 180));
	return (matrix);
}

void	ft_rotate(char *flag, t_a *a)
{
	t_map	*node;
	double	**mat;
	double	*vector;
	double	*new_vec;
	vector = ft_calloc(4, sizeof(double));
	new_vec = ft_calloc(4, sizeof(double));
	if (strcmp(flag, "yaw") == 0)
		mat = ft_yaw(a->ry, a->beta);
	else if (strcmp(flag, "pitch") == 0)
		mat = ft_pitch(a->rx, a->gamma);
	else if (strcmp(flag, "roll") == 0)
		mat = ft_roll(a->rz, a->alpha);
	// printmatrix(mat);
	node = a->map;
	while (node)
	{
		vector[0] = node->a_x;
		vector[1] = node->a_y;
		vector[2] = node->a_z;
		vector[3] = 1;
		new_vec = ft_mat_multi(mat, vector);
		// printf("vector=%f|%f|%f\nnew_vec=%f|%f|%f\n", vector[0], vector[1], vector[2], new_vec[0], new_vec[1], new_vec[2]);
		node->a_x = new_vec[0];
		node->a_y = new_vec[1];
		node->a_z = new_vec[2];
		node = node->next;
	}
	return (free(vector), free(new_vec)); 
}
