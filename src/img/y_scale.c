/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   y_scale.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:24:40 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/10 17:30:58 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	y_scale(t_a *a)
{
	t_map	*node;

	node = a->map;
	while (node)
	{
		node->a_y *= a->y_scale;
		node = node->next;
	}
}
