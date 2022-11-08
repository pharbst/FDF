/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks_numpad.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:16:15 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/08 12:40:09 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	keyhook_num1(t_a *a)
{
	if (mlx_is_key_down(a->mlx, MLX_KEY_KP_0))
		a->keys.num_0 = 1;
	else
		a->keys.num_0 = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_KP_1))
		a->keys.num_1 = 1;
	else
		a->keys.num_1 = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_KP_2))
		a->keys.num_2 = 1;
	else
		a->keys.num_2 = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_KP_3))
		a->keys.num_3 = 1;
	else
		a->keys.num_3 = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_KP_4))
		a->keys.num_4 = 1;
	else
		a->keys.num_4 = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_KP_5))
		a->keys.num_5 = 1;
	else
		a->keys.num_5 = 0;
}

void	keyhook_num2(t_a *a)
{
	if (mlx_is_key_down(a->mlx, MLX_KEY_KP_6))
		a->keys.num_6 = 1;
	else
		a->keys.num_6 = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_KP_7))
		a->keys.num_7 = 1;
	else
		a->keys.num_7 = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_KP_8))
		a->keys.num_8 = 1;
	else
		a->keys.num_8 = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_KP_9))
		a->keys.num_9 = 1;
	else
		a->keys.num_9 = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_KP_ADD))
		a->keys.add = 1;
	else
		a->keys.add = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_KP_SUBTRACT))
		a->keys.sub = 1;
	else
		a->keys.sub = 0;
}