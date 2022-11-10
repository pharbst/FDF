/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recalc_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:28:33 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/10 17:13:48 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	recalc_img(t_a *a)
{
	ft_bzero(a->img->pixel, a->img->width * a->img->height * sizeof(t_pixel));
	reset_coords(a);
	// y_scale(a);
	rotate("pitch", a);
	rotate("yaw", a);
	rotate("roll", a);
	zoom(a);
	get_img_coords(a);
	offset(a);
	img_draw(a);
}
