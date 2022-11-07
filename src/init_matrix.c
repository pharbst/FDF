/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:14:11 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/02 17:15:02 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	alloc_matrix(t_a *a)
{
	int	i;

	i = 0;
	a->rx = ft_calloc(4, sizeof(double *));
	if (!a->rx)
		ft_exit(a);
	a->ry = ft_calloc(4, sizeof(double *));
	if (!a->ry)
		ft_exit(a);
	a->rz = ft_calloc(4, sizeof(double *));
	if (!a->rz)
		ft_exit(a);
	while (i < 4)
	{
		a->rx[i] = ft_calloc(4, sizeof(double));
		if (!a->rx[i])
			ft_exit(a);
		a->ry[i] = ft_calloc(4, sizeof(double));
		if (!a->ry[i])
			ft_exit(a);
		a->rz[i] = ft_calloc(4, sizeof(double));
		if (!a->rz[i])
			ft_exit(a);
		i++;
	}
}

void	init_matrix(t_a *a)
{
	alloc_matrix(a);
	a->rx[0][0] = 1;
	a->rx[3][3] = 1;
	a->ry[1][1] = 1;
	a->ry[3][3] = 1;
	a->rz[2][2] = 1;
	a->rz[3][3] = 1;
}
