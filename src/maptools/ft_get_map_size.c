/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:15:16 by pharbst           #+#    #+#             */
/*   Updated: 2022/10/22 20:30:49 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_get_map_size(t_a *a)
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
	if ((head = head->next))
		j++;
	while (head->down)
	{
		j++;
		head = head->down;
	}
	(*(unsigned int *) &a->map_x) = i;
	(*(unsigned int *) &a->map_z) = j;
}
