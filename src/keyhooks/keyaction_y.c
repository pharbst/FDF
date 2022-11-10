/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyaction_y.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 02:13:23 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/10 02:17:09 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	keyaction_y(t_a *a)
{
	t_map	*node;

	if (a->keys.z && !a->keys.x)
	{
		reset_coords(a);
		node = a->map;
		while (node)
		{
			node->a_y += 1;
			node = node->next;
		}
	}
	else if (a->keys.x && !a->keys.z)
	{
		reset_coords(a);
		node = a->map;
		while (node)
		{
			node->a_y -= 1;
			node = node->next;
		}
	}
}
