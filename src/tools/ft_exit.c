/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:52:12 by pharbst           #+#    #+#             */
/*   Updated: 2022/10/29 14:00:54 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_exit(t_a *a)
{
	int	i;

	i = -1;
	if (a->rx)
		while (++i < 4)
			free(a->rx[i]);
	i = -1;
	if (a->ry)
		while (++i < 4)
			free(a->ry[i]);
	i = -1;
	if (a->rz)
		while (++i < 4)
			free(a->rz[i]);
	if (a->rx)
		free(a->rx);
	if (a->ry)
		free(a->ry);
	if(a->rz)
		free(a->rz);
	if (a->img)
		free(a->img);
	free(a);
}
