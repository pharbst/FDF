/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_arrow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:20:50 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/09 17:23:39 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	keyhook_arrow(t_a *a)
{
	if (mlx_is_key_down(a->mlx, MLX_KEY_UP))
		a->keys.up = 1;
	else
		a->keys.up = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_DOWN))
		a->keys.down = 1;
	else
		a->keys.down = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_LEFT))
		a->keys.left = 1;
	else
		a->keys.left = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_RIGHT))
		a->keys.right = 1;
	else
		a->keys.right = 0;
}
