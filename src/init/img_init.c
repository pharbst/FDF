/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:24:16 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/03 15:29:24 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	img_init(t_a *a)
{
	a->img = ft_calloc(1, sizeof(t_img));
	if (!a->img)
		ft_exit(a);
	(*(unsigned int *)&a->img->width) = a->mlximg->width;
	(*(unsigned int *)&a->img->height) = a->mlximg->height;
	a->img->count = a->mlximg->count;
	a->img->pixel = (t_pixel *)a->mlximg->pixels;
	a->img->instances = a->mlximg->instances;
	a->img->context = a->mlximg->context;
}
