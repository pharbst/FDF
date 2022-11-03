/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:27:15 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/02 20:22:17 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_print_map(t_map *head)
{
	int i = 1;

	while (head)
	{
		printf("node%i	", i);
		printf("node= %p || next= %15p || right= %15p || down= %15p || color= %8x || x= %15f || y= %15f || z= %15f || a_x= %15f || a_y= %15f || a_z= %15f\n", head, head->next, head->right, head->down, head->color.pixel, head->x, head->y, head->z, head->a_x, head->a_y, head->a_z);
		head = head->next;
		i++;
	}
	printf("\n\n\n");
}
