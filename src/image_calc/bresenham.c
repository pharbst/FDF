/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:37:26 by pharbst           #+#    #+#             */
/*   Updated: 2022/10/29 15:27:05 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_fdx(t_bre vars, t_a *a)
{
	vars.fd = vars.dx;
	vars.sd = vars.dy;
	vars.f = vars.fd / 2.0;
	while (vars.x0 < vars.x1)
	{
		// printf("%d|%d\n", vars.x0, vars.y0);
		ft_set_pixel(vars.x0, vars.y0, a->img, 0XFFFFFFFF);
		vars.x0++;
		vars.f = vars.f - vars.sd;
		if (vars.f < 0)
		{
			vars.y0++;
			vars.f += vars.fd;
		}
	}
}

void	ft_fdy(t_bre vars, t_a *a)
{
	vars.fd = vars.dy;
	vars.sd = vars.dx;
	vars.f = vars.fd / 2.0;
	while (vars.y0 < vars.y1)
	{
		// printf("%d|%d\n", vars.x0, vars.y0);
		ft_set_pixel(vars.x0, vars.y0, a->img, 0XFFFFFFFF);
		vars.y0++;
		vars.f = vars.f - vars.sd;
		if (vars.f < 0)
		{
			vars.x0++;
			vars.f += vars.fd;
		}
	}
}

void	ft_draw_line(unsigned int *vector1, unsigned int *vector2, t_a *a)
{
	t_bre	vars;

	vars.x0 = vector1[0];
	vars.x1 = vector2[0];
	vars.y0 = vector1[1];
	vars.y1 = vector2[1];
	vars.dx = vars.x1 - vars.x0;
	vars.dy = vars.y1 - vars.y0;
	if (vars.dx > vars.dy)
		ft_fdx(vars, a);
	else
		ft_fdy(vars, a);
	return ;
}
