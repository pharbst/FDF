/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:27:15 by pharbst           #+#    #+#             */
/*   Updated: 2022/10/17 15:55:57 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_print_map(t_map *head)
{
	int i = 1;

	while (head)
	{
		printf("node%i	", i);
		printf("node= %p || next= %15p || right= %15p || down= %15p || color= %8x || y= %i\n", head, head->next, head->right, head->down, head->color.pixel, head->y);
		head = head->next;
		i++;
	}
}