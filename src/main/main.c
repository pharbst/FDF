/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:29:48 by pharbst           #+#    #+#             */
/*   Updated: 2022/09/27 17:03:56 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

mlx_image_t	*g_img;

void	hook(void *param)
{
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
	if (mlx_is_key_down(param, MLX_KEY_UP))
		g_img->instances[0].y -= 5;
	if (mlx_is_key_down(param, MLX_KEY_DOWN))
		g_img->instances[0].y += 5;
	if (mlx_is_key_down(param, MLX_KEY_LEFT))
		g_img->instances[0].x -= 5;
	if (mlx_is_key_down(param, MLX_KEY_RIGHT))
		g_img->instances[0].x += 5;
}

int	main(void)
{
	mlx_t	*mlx;
	unsigned int	x;
	unsigned int	y;

	y = 0;
	mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, 50, 10);
	while (y < g_img->height)
	{
		x = 0;
		while (x < g_img->width)
		{
			g_img->pixels[x * 4 + y * g_img->width * 4 + 0] = 0x00;		//R
			g_img->pixels[x * 4 + y * g_img->width * 4 + 1] = 0xFF;		//G
			g_img->pixels[x * 4 + y * g_img->width * 4 + 2] = 0x00;		//B
			g_img->pixels[x * 4 + y * g_img->width * 4 + 3] = 0xFF;		//alpha
			x++;
		}
		y++;
	}
	// memset(g_img->pixels, 0xFF , g_img->width * g_img->height * sizeof(int));
	mlx_image_to_window(mlx, g_img, 1300, 800);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}


