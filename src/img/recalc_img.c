/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recalc_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:28:33 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/10 16:19:46 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	zoom(t_a *a)
{
	t_map	*node;

	node = a->map;
	while (node)
	{
		node->a_x *= a->zoom;
		node->a_y *= a->zoom;
		node->a_z *= a->zoom;
		node = node->next;
	}
}

void	recalc_img(t_a *a)
{
	ft_bzero(a->img->pixel, a->img->width * a->img->height * sizeof(t_pixel));
	reset_coords(a);
	rotate("pitch", a);
	rotate("yaw", a);
	rotate("roll", a);
	zoom(a);
	get_img_coords(a);
	offset(a);
	img_draw(a);
}
