/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:37:26 by pharbst           #+#    #+#             */
/*   Updated: 2022/10/22 16:54:54 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include <stdio.h>

void	ft_fdx(t_lvar vars)
{
	vars.fd = vars.dx;
	vars.sd = vars.dy;
	vars.f = vars.fd / 2.0;
	while (vars.x0 < vars.x1)
	{
		printf("%d|%d\n", vars.x0, vars.y0);
		vars.x0++;
		vars.f = vars.f - vars.sd;
		if (vars.f < 0)
		{
			vars.y0++;
			vars.f += vars.fd;
		}
	}
}

void	ft_fdy(t_lvar vars)
{
	vars.fd = vars.dy;
	vars.sd = vars.dx;
	vars.f = vars.fd / 2.0;
	while (vars.y0 < vars.y1)
	{
		printf("%d|%d\n", vars.x0, vars.y0);
		vars.y0++;
		vars.f = vars.f - vars.sd;
		if (vars.f < 0)
		{
			vars.x0++;
			vars.f += vars.fd;
		}
	}
}

void	ft_draw_line(t_lvar vars)
{
	vars.dx = vars.x1 - vars.x0;
	vars.dy = vars.y1 - vars.y0;
	if (vars.dx > vars.dy)
		ft_fdx(vars);
	else
		ft_fdy(vars);
	return ;
}
