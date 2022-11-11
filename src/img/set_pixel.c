/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:58:20 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/09 17:16:43 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	set_pixel(unsigned int x, unsigned int y, t_img *img,
				unsigned int color)
{
	img->pixel[x + y * img->width].pixel = color;
}
