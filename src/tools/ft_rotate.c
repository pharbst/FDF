/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:46:14 by pharbst           #+#    #+#             */
/*   Updated: 2022/10/28 15:12:29 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_rotate(char *flag, double angel, t_a *a)
{
	t_map	*node;
	double	**mat;
	double	*vector;
	double	*new_vec;

	node = a->map;
	if (strcmp(flag, "yaw") == 0)
		mat = a->ry;
	if (strcmp(flag, "pitch") == 0)
		mat = a->rx;
	if (strcmp(flag, "roll") == 0)
		mat = a->rz;
	while (node)
	{
		vector[0] = node->x;
		vector[1] = node->y;
		vector[2] = node->z;
		vector[3] = 1;
		new_vec = ft_mat_multi(mat, vector, angel, flag);
		node = node->next;
	}
}
