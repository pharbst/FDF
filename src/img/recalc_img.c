/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recalc_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:28:33 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/08 14:46:36 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	recalc_img(t_a *a)
{
	ft_bzero(a->img->pixel, a->img->width * a->img->height * sizeof(t_pixel));
	rotate("yaw", a);
	rotate("pitch", a);
	rotate("roll", a);
	offset(a);
	img_calc(a);
}