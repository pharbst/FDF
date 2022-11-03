/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:00:07 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/02 19:34:50 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_img_calc(t_a *a)
{
	t_map			*node;
	unsigned int	*vector1;
	unsigned int	*vector2;

	node = a->map;
	while (node)
	{
		node->img_x = a->img->width/2 + node->a_x;
		node->img_y = a->img->height/2 + (-node->a_y);
		node = node->next;
	}
	vector1 = ft_calloc(2, sizeof(unsigned int));
	vector2 = ft_calloc(2, sizeof(unsigned int));
	node = a->map;
	while (node)
	{
		if (node->right)
		{
			vector1[0] = node->img_x;
			vector1[1] = node->img_x;
			vector2[0] = node->right->img_x;
			vector2[1] = node->right->img_y;
			ft_draw_line(vector1, vector2, a);
		}
		if (node->down)
		{
			vector1[0] = node->img_x;
			vector1[1] = node->img_x;
			vector2[0] = node->down->img_x;
			vector2[1] = node->down->img_y;
			// ft_draw_line(vector1, vector2, a);
		}
		node = node->next;
	}
	return (free(vector1), free(vector2));
}
