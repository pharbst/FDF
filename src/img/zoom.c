/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:10:49 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/10 17:10:54 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(t_a *a)
{
	t_map	*node;

	node = a->map;
	while (node)
	{
		node->a_x *= a->zoom;
		node->a_y *= a->zoom;
		node->a_z *= a->zoom;
		node = node->next;
	}
}
