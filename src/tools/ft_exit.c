/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:25:29 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/09 16:01:35 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	free_matrix(t_a *a)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (a->rx[i])
			free(a->rx[i]);
		if (a->ry[i])
			free(a->ry[i]);
		if (a->rz[i])
			free(a->rz[i]);
		i++;
	}
	free(a->rx);
	free(a->ry);
	free(a->rz);
}

void	ft_exit(t_a *a)
{
	if (!a)
		exit(0);
	free_matrix(a);
	if (a->map)
		free_map(a);
	exit(0);
}
