/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:20:20 by pharbst           #+#    #+#             */
/*   Updated: 2022/10/22 20:31:13 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void draw(t_a *a)
{
	t_map	*node = a->map;
	unsigned x = a->x;
	unsigned z = a->z;

	while (node)
	{
			// node = node->down;
		if (node->y == 2)
			ft_set_pixel(x, z, a->img, 0XFFFFFFFF);
		else
			ft_set_pixel(x, z, a->img, a->color.pixel);
		printf("%u |%u\n", x, z);
		if (node->right)
			x += a->i;
		if (!node->right)
			x -= (a->map_x - 1) * a->i;
		if (!node->right)
			z += a->i;
		node = node->next;
	}
	
}
