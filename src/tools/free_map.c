/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:35:32 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/06 20:17:56 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	free_map(t_a *a)
{
	t_map   *node;
	t_map   *next;

	if (!a->map)
		return ;
	node = a->map;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	free(a->map);
}
