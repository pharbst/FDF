/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:00:07 by pharbst           #+#    #+#             */
/*   Updated: 2022/10/28 18:29:37 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_img_calc(t_a *a)
{
	t_map	*node;

	node = a->map;
	while (node)
	{
		node->img_x = a->img->width/2 + node->a_x;
		node->img_y = a->img->height/2 + (-node->a_y);
		node = node->next;
	}
	node = a->map;
	while (node)
	{
		if (node->right)
			ft_draw_line(node->img_x, node->right->img_x, node->img_y, node->right->img_y);
		if (node->down)
			ft_draw_line(node->img_x, node->down->img_x, node->img_y, node->down->img_y);
		node = node->next;
	}
}
