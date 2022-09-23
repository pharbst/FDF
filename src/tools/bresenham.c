/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:37:26 by pharbst           #+#    #+#             */
/*   Updated: 2022/09/19 18:50:55 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

plotLine(x0, y0, x1, y1)
{
	int	dx;
	int	sx;
	int	dy;
	int	error;

	dx = abs(x1 - x0)
	sx = x0 < x1 ? 1 : -1
	dy = -abs(y1 - y0)
	sy = y0 < y1 ? 1 : -1
	error = dx + dy

	while true
	{
		plot(x0, y0);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * error
		if (e2 >= dy)
		{
			if (x0 == x1)
				break ;
			error = error + dy
			x0 = x0 + sx
		}
		if (e2 <= dx)
		{
			if (y0 == y1)
				break ;
			error = error + dx
			y0 = y0 + sy
		}
	}
}


void	plot_line (int x0, int y0, int x1, int y1)
{
	int	dx;
	int	dy;
	int	err;
	int	sx;
	int	sy;
	int	e2;

	dx = abs (x1 - x0);
	sx = x0 < x1 ? 1 : -1;
	dy = -abs (y1 - y0);
	sy = y0 < y1 ? 1 : -1; 
	err = dx + dy, e2; /* error value e_xy */
	for ()
	{
		setPixel (x0,y0);
		if (x0 == x1 && y0 == y1) break;
		e2 = 2 * err;
		if (e2 >= dy) { err += dy; x0 += sx; }
		if (e2 <= dx) { err += dx; y0 += sy; }
	}
}