/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map_xz.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 19:22:36 by pharbst           #+#    #+#             */
/*   Updated: 2022/10/28 12:15:32 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_init_map_xz(t_a *a)
{
	t_map			*node;
	double	i;
	double	x;
	double	z;

	node = a->map;
	printf("hier\n");
	if (a->map_x > a->map_z)
	{
		i = 1000.0 / (a->map_x - 1);
		z = -(a->map_z - 1.0) / 2 * i;
		printf("%f\n", z);
		x = -500.0;
	}
	else
	{
		i = 1000.0 / (a->map_z - 1);
		z = -500.0;
		x = -(a->map_x - 1.0) / 2 * i;
	}
	printf("init coords|%f|%f|\n", x, z);
	while (node)
	{
		node->x = x;
		node->z = z;
		if (node->right)
			x += i;
		else
		{
			x -= i * (a->map_x - 1);
			z += i;
		}
		node = node->next;
	}
}
