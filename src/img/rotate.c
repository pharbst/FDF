/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:46:14 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/18 17:41:56 by pharbst          ###   ########.fr       */
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

static void	rotate_helper(double *vector, t_map *node, double **mat)
{
	double	*new_vec;

	while (node)
	{
		vector[0] = node->a_x;
		vector[1] = node->a_y;
		vector[2] = node->a_z;
		vector[3] = 1;
		new_vec = mat_multi(mat, vector);
		node->a_x = new_vec[0];
		node->a_y = new_vec[1];
		node->a_z = new_vec[2];
		free(new_vec);
		node = node->next;
	}
}

void	rotate(char *flag, t_a *a)
{
	t_map	*node;
	double	**mat;
	double	*vector;

	node = a->map;
	vector = ft_calloc(4, sizeof(double));
	if (ft_strcmp(flag, "yaw") == 0)
		mat = ft_yaw(a->ry, a->gamma);
	if (ft_strcmp(flag, "pitch") == 0)
		mat = ft_pitch(a->rx, a->beta);
	if (ft_strcmp(flag, "roll") == 0)
		mat = ft_roll(a->rz, a->alpha);
	rotate_helper(vector, node, mat);
	free(vector);
}
