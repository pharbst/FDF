/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:29:48 by pharbst           #+#    #+#             */
/*   Updated: 2022/10/15 15:24:50 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../MLX42/include/MLX42/MLX42.h"

// typedef union s_pixel
// {
// 	struct
// 	{
// 		char	r;
// 		char	g;
// 		char	b;
// 		char	a;
// 	};
// 	unsigned int	pixel;
// }	t_pixel;

// typedef struct s_img
// {
// 	const unsigned int	height;
// 	const unsigned int	width;
// 	int					count;
// 	t_pixel				*pixel;
// 	mlx_instance_t		*instance;
// 	void				*context;
// }	t_img;

t_img	*ft_init_img(mlx_image_t *g_img)
{
	t_img	*img;

	img = ft_calloc(1, sizeof(t_img));
	if (!img)
		return (NULL);
	(*(unsigned int *)&img->width) = g_img->width;
	(*(unsigned int *)&img->height) = g_img->height;
	img->count = g_img->count;
	img->pixel = (t_pixel *)g_img->pixels;
	img->instance = g_img->instances;
	img->context = g_img->context;
	return (img);
}

// void	hook(void *param)
// {
// 	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
// 		mlx_close_window(param);
// 	if (mlx_is_key_down(param, MLX_KEY_UP))
// 		g_img->instances[0].y -= 5;
// 	if (mlx_is_key_down(param, MLX_KEY_DOWN))
// 		g_img->instances[0].y += 5;
// 	if (mlx_is_key_down(param, MLX_KEY_LEFT))
// 		g_img->instances[0].x -= 5;
// 	if (mlx_is_key_down(param, MLX_KEY_RIGHT))
// 		g_img->instances[0].x += 5;
// }

int	main(int argc, char **argv)
{
	int				fd;
	mlx_image_t		*g_img;
	mlx_t			*mlx;
	// unsigned int	x;
	// unsigned int	y;
	t_img			*img;
	// char			**line;
	// unsigned int	i = 0;
	t_map			*map;
	unsigned int	map_size_x;
	unsigned int	map_size_z;

	if (argc != 2)
		return (0);
	fd = 0;
	fd = open(argv[1], O_RDONLY);
	mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, 2560, 1330);
	img = ft_init_img(g_img);
	if (!img)
		return (0);
	map = ft_get_map(fd);
	ft_print_map(map);
	ft_get_map_size(&map_size_x, &map_size_z, map);
	printf("x= %u | z= %u\n", map_size_x, map_size_z);

	// mlx_image_to_window(mlx, g_img, 0, 0);
	// // mlx_loop_hook(mlx, &hook, mlx);
	// mlx_loop(mlx);
	// mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
