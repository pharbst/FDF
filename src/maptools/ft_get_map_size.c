/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:15:16 by pharbst           #+#    #+#             */
/*   Updated: 2022/10/15 15:54:56 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_get_map_size(unsigned int *x, unsigned int *y, t_map *head)
{
	unsigned int	i;
	unsigned int	j;

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
	*x = i;
	*y = j;
}
