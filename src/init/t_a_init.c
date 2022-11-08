/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_a_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:09:21 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/08 14:32:39 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	t_a_init(t_a *a)
{
	a->mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	if (!a->mlx)
		ft_exit(a);
	a->mlximg = mlx_new_image(a->mlx, WIDTH, HEIGHT);
	ft_bzero(a->mlximg->pixels, WIDTH * HEIGHT * sizeof(t_pixel));
	if (!a->mlximg)
		ft_exit(a);
	img_init(a);
	if (!a->img)
		ft_exit(a);
	init_matrix(a);
}
