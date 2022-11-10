/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_coords.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:17:22 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/09 23:18:09 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_coords(t_a *a)
{
	t_map	*node;

	node = a->map;
	while (node)
	{
		node->a_x = node->x;
		node->a_y = node->y;
		node->a_z = node->z;
		node = node->next;
	}
}
