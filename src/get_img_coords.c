/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img_coords.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:38:24 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/07 12:40:50 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_img_coords(t_a *a)
{
	t_map			*node;

	node = a->map;
	while (node)
	{
		node->img_x = a->img->width/2 + node->a_x;
		node->img_y = a->img->height/2 + (-node->a_y);
		node = node->next;
	}
}