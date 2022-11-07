/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:27:15 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/07 10:22:10 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_print_map(t_map *head)
{
	int i = 1;

	while (head)
	{
		printf("node%i	", i);
		printf("color= %12u || x= %15f || y= %15f || z= %15f || a_x= %15f || a_y= %15f || a_z= %15f || img_x %11u || img_y %11u\n", head->color.pixel, head->x, head->y, head->z, head->a_x, head->a_y, head->a_z, head->img_x, head->img_y);
		head = head->next;
		i++;
	}
	printf("\n\n\n");
}
