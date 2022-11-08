/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:37:52 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/08 11:20:21 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../includes/fdf_struct.h"

void	offset(t_a *a)
{
	t_map	*node;

	node = a->map;
	while (node)
	{
		node->img_x += a->trans_x;
		node->img_y += a->trans_y;
		node = node->next;
	}
}
