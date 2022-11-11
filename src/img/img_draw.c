/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:00:07 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/10 00:55:31 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	img_draw(t_a *a)
{
	t_map			*node;
	unsigned int	vector1[2];
	unsigned int	vector2[2];
	unsigned int	color;

	node = a->map;
	while (node)
	{
		color = node->color.pixel;
		if (node->right)
		{
			vector1[0] = node->img_x;
			vector1[1] = node->img_y;
			vector2[0] = node->right->img_x;
			vector2[1] = node->right->img_y;
			draw_line(vector1, vector2, a, color);
		}
		if (node->down)
		{
			vector1[0] = node->img_x;
			vector1[1] = node->img_y;
			vector2[0] = node->down->img_x;
			vector2[1] = node->down->img_y;
			draw_line(vector1, vector2, a, color);
		}
		node = node->next;
	}
}
