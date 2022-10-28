/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:40:07 by pharbst           #+#    #+#             */
/*   Updated: 2022/10/28 15:11:30 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_img	*ft_init_img(mlx_image_t *mlximg)
{
	t_img	*img;

	img = ft_calloc(1, sizeof(t_img));
	if (!img)
		return (NULL);
	(*(unsigned int *)&img->width) = mlximg->width;
	(*(unsigned int *)&img->height) = mlximg->height;
	img->count = mlximg->count;
	img->pixel = (t_pixel *)mlximg->pixels;
	img->instances = mlximg->instances;
	img->context = mlximg->context;
	return (img);
}

void	ft_init_t_a(t_a *a)
{
	int i;

	i = 0;
	a->rx = ft_calloc(4, sizeof(double *));
	a->ry = ft_calloc(4, sizeof(double *));
	a->rz = ft_calloc(4, sizeof(double *));
	while (i < 4)
	{
		a->rx[i] = ft_calloc(4, sizeof(double));
		a->ry[i] = ft_calloc(4, sizeof(double));
		a->rz[i] = ft_calloc(4, sizeof(double));
		i++;
	}
	a->rx[0][0] = 1;
	a->rx[3][3] = 1;
	a->ry[1][1] = 1;
	a->ry[3][3] = 1;
	a->rz[2][2] = 1;
	a->rz[3][3] = 1;
	a->mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	if (!a->mlx)
		exit(EXIT_FAILURE);
	a->mlximg = mlx_new_image(a->mlx, WIDTH, HEIGHT);
	a->img = ft_init_img(a->mlximg);
	if (!a->img)
		exit(EXIT_FAILURE);
}
