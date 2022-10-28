/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:29:48 by pharbst           #+#    #+#             */
/*   Updated: 2022/10/28 14:09:39 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../MLX42/include/MLX42/MLX42.h"

void	ft_keyhook(t_a *a)
{
	if (mlx_is_key_down(a->mlx, MLX_KEY_A))
		a->color.r++;
	if (mlx_is_key_down(a->mlx, MLX_KEY_S))
		a->color.r--;
	if (mlx_is_key_down(a->mlx, MLX_KEY_D))
		a->color.b++;
	if (mlx_is_key_down(a->mlx, MLX_KEY_F))
		a->color.b--;
	if (mlx_is_key_down(a->mlx, MLX_KEY_G))
		a->color.g++;
	if (mlx_is_key_down(a->mlx, MLX_KEY_H))
		a->color.g--;
	if (mlx_is_key_down(a->mlx, MLX_KEY_J))
		a->color.a++;
	if (mlx_is_key_down(a->mlx, MLX_KEY_K))
		a->color.a--;
}

void	hook(void *param)
{
	t_a	*a;

	a = param;
	
	draw(a);
	ft_keyhook(a);
	// ft_recalculate(a);
}

void	ft_start(t_a *a)
{
	a->map = ft_get_map(a->fd);
	close(a->fd);
	
	// debug
	ft_print_map(a->map);

	ft_get_map_size(a);

	// debug
	printf("x= %u | z= %u\n", a->map_x, a->map_z);

	// ft_calculate_first_image(a);

	// if ((a->img->width - 100) / (a->map_x - 1) > (a->img->height - 50) / (a->map_z -1))
	// 	a->i = (a->img->height - 50) / (a->map_z -1);
	// else
	// 	a->i = (a->img->width - 100) / (a->map_x - 1);
}

int	main(int argc, char **argv)
{
	t_a				*a;

	if (argc != 2)
		return (0);
	a = ft_calloc(1, sizeof(t_a));
	ft_init_t_a(a);
	a->fd = open(argv[1], O_RDONLY);
	if (a->fd == -1)
		return (free(a), 0);

	a->map = ft_get_map(a->fd);
	ft_get_map_size(a);
	ft_init_map_xz(a);
	ft_print_map(a->map);
	ft_rotate("yaw", 90, a);
	printf("\n\n\n");
	ft_print_map(a->map);
	free(a);
	// ft_init_t_a(a);
	// ft_start(&a);

	// mlx_image_to_window(a->mlx, a->mlximg, 0, 0);
	// mlx_loop_hook(a->mlx, &hook, &a);
	// mlx_loop(a->mlx);
	// mlx_terminate(a->mlx);
	// return (EXIT_SUCCESS);
	return (0);
}
