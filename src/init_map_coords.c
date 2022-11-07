/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_coords.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:26:00 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/03 16:26:38 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	init_map_coords(t_a *a)
{
	t_map			*node;
	double	i;
	double	x;
	double	z;

	node = a->map;
	if (a->map_x > a->map_z)
	{
		i = 1000.0 / (a->map_x - 1);
		z = -(a->map_z - 1.0) / 2 * i;
		x = -500.0;
	}
	else
	{
		i = 1000.0 / (a->map_z - 1);
		z = -500.0;
		x = -(a->map_x - 1.0) / 2 * i;
	}
	while (node)
	{
		node->x = x;
		node->a_x = x;
		node->z = z;
		node->a_z = z;
		node->a_y = node->y;
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
