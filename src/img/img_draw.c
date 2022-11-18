/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:00:07 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/18 17:47:01 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	draw_helper(t_map **node, t_a *a, unsigned int vector1[2]
				, unsigned int vector2[2])
{
	unsigned int	color;

	color = (*node)->color.pixel;
	if ((*node)->right)
	{
		vector1[0] = (*node)->img_x;
		vector1[1] = (*node)->img_y;
		vector2[0] = (*node)->right->img_x;
		vector2[1] = (*node)->right->img_y;
		draw_line(vector1, vector2, a, color);
	}
	if ((*node)->down)
	{
		vector1[0] = (*node)->img_x;
		vector1[1] = (*node)->img_y;
		vector2[0] = (*node)->down->img_x;
		vector2[1] = (*node)->down->img_y;
		draw_line(vector1, vector2, a, color);
	}
	*node = (*node)->next;
}

void	img_draw(t_a *a)
{
	t_map			*node;
	unsigned int	vector1[2];
	unsigned int	vector2[2];

	node = a->map;
	while (node)
		draw_helper(&node, a, vector1, vector2);
}
