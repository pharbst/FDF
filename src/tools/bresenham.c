/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:37:26 by pharbst           #+#    #+#             */
/*   Updated: 2022/09/27 18:58:37 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <fdf.h>
#include <stdio.h>

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
		f = fd / 2.0;
		while (x0 < x1)
		{
			printf("%d|%d\n", x0, y0);
			x0++;
			f = f - sd;
			if (f < 0)
			{
				y0++;
				f += fd;
			}
		}
	}
	else
	{
		fd = dy;
		sd = dx;
		f = fd / 2.0;
		while (y0 < y1)
		{
			printf("%d|%d\n", x0, y0);
			y0++;
			f = f - sd;
			if (f < 0)
			{
				x0++;
				f += fd;
			}
		}
	}
	return ;
}

int main()
{
	ft_draw_line(0, 0, 15, 10);
	return (0);
}