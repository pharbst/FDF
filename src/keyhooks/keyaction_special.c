/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyaction_special.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:53:09 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/08 21:02:47 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	keyaction_special(t_a *a)
{
	t_map	*node;

	if (a->keys.tab && !a->old_keys.tab)
		ft_print_map(a->map);
	if (a->keys.space && !a->old_keys.space)
	{
		node = a->map;
		while (node)
		{
			node->a_x = node->x;
			node->a_y = node->y;
			node->a_z = node->z;
			node = node->next;
		}
	}
}
