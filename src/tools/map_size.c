/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:43:48 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/09 17:45:52 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	map_size(t_a *a)
{
	unsigned int	i;
	unsigned int	j;
	t_map			*head;

	head = a->map;
	i = 1;
	j = 1;
	while (head->right)
	{
		i++;
		head = head->next;
	}
	head = head->next;
	if (head)
		j++;
	while (head->down)
	{
		j++;
		head = head->down;
	}
	(*(unsigned int *) &a->map_x) = i;
	(*(unsigned int *) &a->map_z) = j;
}
