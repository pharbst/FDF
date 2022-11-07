/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:07:39 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/03 16:22:59 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_w(t_a *a)
{
	printf("w");
	// a->y_offset += 10;
}

void	ft_a(t_a *a)
{
	printf("a");
	// a->x_offset -= 10;
}

void	ft_s(t_a *a)
{
	printf("s");
	// a->y_offset -= 10;
}

void	ft_d(t_a *a)
{
	printf("d");
	// a->x_offset += 10;
}
