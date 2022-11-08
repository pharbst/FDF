/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:10:30 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/08 13:57:40 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	keyhook1(t_a *a)
{
	if (mlx_is_key_down(a->mlx, MLX_KEY_Q))
		a->keys.q = 1;
	else
		a->keys.q = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_W))
		a->keys.w = 1;
	else
		a->keys.w = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_E))
		a->keys.e = 1;
	else
		a->keys.e = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_R))
		a->keys.r = 1;
	else
		a->keys.r = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_T))
		a->keys.t = 1;
	else
		a->keys.t = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_Y))
		a->keys.y = 1;
	else
		a->keys.y = 0;
}

void	keyhook2(t_a *a)
{
	if (mlx_is_key_down(a->mlx, MLX_KEY_U))
		a->keys.u = 1;
	else
		a->keys.u = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_I))
		a->keys.i = 1;
	else
		a->keys.i = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_O))
		a->keys.o = 1;
	else
		a->keys.o = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_P))
		a->keys.p = 1;
	else
		a->keys.p = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_A))
		a->keys.a = 1;
	else
		a->keys.a = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_S))
		a->keys.s = 1;
	else
		a->keys.s = 0;
}

void	keyhook3(t_a *a)
{
	if (mlx_is_key_down(a->mlx, MLX_KEY_D))
		a->keys.d = 1;
	else
		a->keys.d = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_F))
		a->keys.f = 1;
	else
		a->keys.f = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_G))
		a->keys.g = 1;
	else
		a->keys.g = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_H))
		a->keys.h = 1;
	else
		a->keys.h = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_J))
		a->keys.j = 1;
	else
		a->keys.j = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_K))
		a->keys.k = 1;
	else
		a->keys.k = 0;
}

void	keyhook4(t_a *a)
{
	if (mlx_is_key_down(a->mlx, MLX_KEY_L))
		a->keys.l = 1;
	else
		a->keys.l = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_Z))
		a->keys.z = 1;
	else
		a->keys.z = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_X))
		a->keys.x = 1;
	else
		a->keys.x = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_C))
		a->keys.c = 1;
	else
		a->keys.c = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_V))
		a->keys.v = 1;
	else
		a->keys.v = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_B))
		a->keys.b = 1;
	else
		a->keys.b = 0;
}

void	keyhook5(t_a *a)
{
	if (mlx_is_key_down(a->mlx, MLX_KEY_N))
		a->keys.n = 1;
	else
		a->keys.n = 0;
	if (mlx_is_key_down(a->mlx, MLX_KEY_M))
		a->keys.m = 1;
	else
		a->keys.m = 0;
}
