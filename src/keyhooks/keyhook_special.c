/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_special.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:13:43 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/08 12:33:40 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	special_keyhook1(t_a *a)
{
	if (mlx_is_key_down(a->mlx, MLX_KEY_LEFT_SHIFT))
		a->keys.shift = 1;
	else if (mlx_is_key_down(a->mlx, MLX_KEY_RIGHT_SHIFT))
		a->keys.shift = 1;
	else
		a->keys.shift = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_LEFT_CONTROL))
		a->keys.ctrl = 1;
	else if (mlx_is_key_down(a->mlx, MLX_KEY_RIGHT_CONTROL))
		a->keys.ctrl = 1;
	else
		a->keys.ctrl = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_LEFT_ALT))
		a->keys.alt = 1;
	else if (mlx_is_key_down(a->mlx, MLX_KEY_RIGHT_ALT))
		a->keys.alt = 1;
	else
		a->keys.alt = 0;
}

void	special_keyhook2(t_a *a)
{
	if (mlx_is_key_down(a->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(a->mlx);
	if (mlx_is_key_down(a->mlx, MLX_KEY_SPACE))
		a->keys.space = 1;
	else
		a->keys.space = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_TAB))
		a->keys.tab = 1;
	else
		a->keys.tab = 0;
}

void	special_keyhook3(t_a *a)
{
	if (mlx_is_key_down(a->mlx, MLX_KEY_F1))
		a->keys.f1 = 1;
	else
		a->keys.f1 = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_F2))
		a->keys.f2 = 1;
	else
		a->keys.f2 = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_F3))
		a->keys.f3 = 1;
	else
		a->keys.f3 = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_F4))
		a->keys.f4 = 1;
	else
		a->keys.f4 = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_F5))
		a->keys.f5 = 1;
	else
		a->keys.f5 = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_F6))
		a->keys.f6 = 1;
	else
		a->keys.f6 = 0;
}
