/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_a_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:09:21 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/10 01:37:08 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	t_a_init(t_a *a)
{
	a->mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	if (!a->mlx)
		ft_exit(a);
	a->mlximg = mlx_new_image(a->mlx, WIDTH, HEIGHT);
	if (!a->mlximg)
		ft_exit(a);
	img_init(a);
	if (!a->img)
		ft_exit(a);
	a->zoom = 1;
	init_matrix(a);
}
