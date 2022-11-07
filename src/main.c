/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:49:51 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/07 12:52:54 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

mlx_image_t	*g_img;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		g_img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		g_img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		g_img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		g_img->instances[0].x += 5;
}

int	main(int argc, char **argv)
{
	t_a		*a;

	if (argc != 2)
		return (0);
	a = ft_calloc(1, sizeof(t_a));
	if (!a)
		return (0);
	a->fd = open(argv[1], O_RDONLY);
	if (a->fd < 0)
		return (free(a), 0);
	t_a_init(a);
	a->map = read_map(a->fd);
	map_size(a);
	init_map_coords(a);
	ft_print_map(a->map);
	printf("Done\n");
	a->gamma = -90;
	ft_rotate("pitch", a);
	ft_print_map(a->map);
	get_img_coords(a);
	ft_print_map(a->map);
	ft_img_calc(a);
	


	mlx_image_to_window(a->mlx, a->mlximg, 0, 0);
	mlx_loop_hook(a->mlx, &hook, a->mlx);
	mlx_loop(a->mlx);
	mlx_terminate(a->mlx);
	return (EXIT_SUCCESS);
}
