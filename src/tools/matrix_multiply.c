/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:20:41 by pharbst           #+#    #+#             */
/*   Updated: 2022/10/28 14:10:43 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	ft_yaw(int **matrix, double angel)
{
	matrix[0][0] = cos(angel);
	matrix[0][2] = -sin(angel);
	matrix[2][0] = sin(angel);
	matrix[2][2] = cos(angel);
}

static void	ft_pitch(int **matrix, double angel)
{
	matrix[1][1] = cos(angel);
	matrix[1][2] = sin(angel);
	matrix[2][1] = -sin(angel);
	matrix[2][2] = cos(angel);
}

static void	ft_roll(int **matrix, double angel)
{
	matrix[0][0] = cos(angel);
	matrix[0][1] = -sin(angel);
	matrix[1][0] = sin(angel);
	matrix[1][1] = cos(angel);
}

int	*ft_mat_multi(int **matrix, int *vector, double angel, char *flag)
{
	int	*ret;

	
	ret = malloc(4 * sizeof(int));
	if (strcmp(flag, "yaw") == 0)
		ft_yaw(matrix, angel);
	if (strcmp(flag, "pitch") == 0)
		ft_pitch(matrix, angel);
	if (strcmp(flag, "roll") == 0)
		ft_roll(matrix, angel);
	ret[0] = matrix[0][0] * vector[0] + matrix[0][1] * vector[1] + matrix[0][2] * vector[2] + matrix[0][3] * vector[3];
	ret[1] = matrix[1][0] * vector[0] + matrix[1][1] * vector[1] + matrix[1][2] * vector[2] + matrix[1][3] * vector[3];
	ret[2] = matrix[2][0] * vector[0] + matrix[2][1] * vector[1] + matrix[2][2] * vector[2] + matrix[2][3] * vector[3];
	ret[3] = matrix[3][0] * vector[0] + matrix[3][1] * vector[1] + matrix[3][2] * vector[2] + matrix[3][3] * vector[3];
	return (ret);
}
