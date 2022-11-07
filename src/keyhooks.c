/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:10:30 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/03 16:03:32 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_keyhook(t_a *a)
{
	if (mlx_is_key_down(a->mlx, MLX_KEY_UP))
		ft_up(a);
	if (mlx_is_key_down(a->mlx, MLX_KEY_DOWN))
		ft_down(a);
	if (mlx_is_key_down(a->mlx, MLX_KEY_LEFT))
		ft_left(a);
	if (mlx_is_key_down(a->mlx, MLX_KEY_RIGHT))
		ft_right(a);
	if (mlx_is_key_down(a->mlx, MLX_KEY_W))
		ft_w(a);
	if (mlx_is_key_down(a->mlx, MLX_KEY_A))
		ft_a(a);
	if (mlx_is_key_down(a->mlx, MLX_KEY_S))
		ft_s(a);
	if (mlx_is_key_down(a->mlx, MLX_KEY_D))
		ft_d(a);
}

void	ft_addkeyhook(t_a *a)
{
	if (mlx_is_key_down(a->mlx, MLX_KEY_SPACE))
		ft_space(a);
	if (mlx_is_key_down(a->mlx, MLX_KEY_TAB))
		ft_tab(a);
	if (mlx_is_key_down(a->mlx, MLX_KEY_LEFT_SHIFT))
		a->keys->shift = 1;
	else if (mlx_is_key_down(a->mlx, MLX_KEY_RIGHT_SHIFT))
		a->keys->shift = 1;
	else
		a->keys->shift = 0;
}
