/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:37:26 by pharbst           #+#    #+#             */
/*   Updated: 2022/09/27 17:55:28 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_draw_line(int x0, int y0, int x1, int y1)
{
	int		dx;
	int		dy;
	double	sr;
	int		f;

	dx = x1 - x0;
	dy = y1 - y0;
	if (dx > dy)
		sr = dx;
	else
		sr = dy;
	f = sr / 2;
	
	return ;
}
