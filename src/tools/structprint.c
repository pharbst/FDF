/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:27:15 by pharbst           #+#    #+#             */
/*   Updated: 2022/10/14 15:56:57 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_print_map(t_map *head)
{
	while (head)
	{
		printf("%p || %p || %p || %p || %x || %i\n", head, head->next, head->right, head->down, head->color.pixel, head->y);
		head = head->next;
	}
}
