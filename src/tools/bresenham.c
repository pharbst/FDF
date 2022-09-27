/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:37:26 by pharbst           #+#    #+#             */
/*   Updated: 2022/09/27 18:34:01 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_draw_line(int x0, int y0, int x1, int y1)
{
	int		dx;
	int		dy;
	int		fd;
	int		sd;
	double	f;
	double	ft;

	dx = x1 - x0;
	dy = y1 - y0;
	if (dx > dy)
	{
		fd = dx;
		sd = dy;
	}
	else
	{
		fd = dy;
		sd = dx;
	}
	f = fd / 2.0;
	while ()
	{
		ft_putpixel(x0, y0);
		x0++;
		f = f - sd;
		if (f < 0)
		{
			y0++;
			f += fd;
		}
	}
	return ;
}
