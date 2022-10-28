/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:37:26 by pharbst           #+#    #+#             */
/*   Updated: 2022/10/28 18:38:31 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include <stdio.h>

void	ft_fdx(t_bre vars)
{
	vars.fd = vars.dx;
	vars.sd = vars.dy;
	vars.f = vars.fd / 2.0;
	while (vars.x0 < vars.x1)
	{
		// printf("%d|%d\n", vars.x0, vars.y0);
		vars.x0++;
		vars.f = vars.f - vars.sd;
		if (vars.f < 0)
		{
			vars.y0++;
			vars.f += vars.fd;
		}
	}
}

void	ft_fdy(t_bre vars)
{
	vars.fd = vars.dy;
	vars.sd = vars.dx;
	vars.f = vars.fd / 2.0;
	while (vars.y0 < vars.y1)
	{
		// printf("%d|%d\n", vars.x0, vars.y0);
		vars.y0++;
		vars.f = vars.f - vars.sd;
		if (vars.f < 0)
		{
			vars.x0++;
			vars.f += vars.fd;
		}
	}
}

void	ft_draw_line(unsigned int x0, unsigned int x1, unsigned int y0, unsigned int y1)
{
	t_bre	vars;

	vars.x0 = x0;
	vars.x1 = x1;
	vars.y0 = y0;
	vars.y1 = y1;
	vars.dx = vars.x1 - vars.x0;
	vars.dy = vars.y1 - vars.y0;
	if (vars.dx > vars.dy)
		ft_fdx(vars);
	else
		ft_fdy(vars);
	return ;
}
