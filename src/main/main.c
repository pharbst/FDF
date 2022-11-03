/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:29:48 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/02 20:46:29 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../MLX42/include/MLX42/MLX42.h"

void	ft_keyhook(t_a *a)
{
	// if (mlx_is_key_down(a->mlx, MLX_KEY_A))
	// 	a->color.r++;
	// if (mlx_is_key_down(a->mlx, MLX_KEY_S))
	// 	a->color.r--;
	// if (mlx_is_key_down(a->mlx, MLX_KEY_D))
	// 	a->color.b++;
	// if (mlx_is_key_down(a->mlx, MLX_KEY_F))
	// 	a->color.b--;
	// if (mlx_is_key_down(a->mlx, MLX_KEY_G))
	// 	a->color.g++;
	// if (mlx_is_key_down(a->mlx, MLX_KEY_H))
	// 	a->color.g--;
	// if (mlx_is_key_down(a->mlx, MLX_KEY_J))
	// 	a->color.a++;
	// if (mlx_is_key_down(a->mlx, MLX_KEY_K))
	// 	a->color.a--;
	if (mlx_is_key_down(a->mlx, MLX_KEY_SPACE))
	{
		a->alpha = 0;
		a->beta = 0;
		a->gamma = 0;
	}
	if (mlx_is_key_down(a->mlx, MLX_KEY_UP))
		a->alpha +=0.01;
	if (mlx_is_key_down(a->mlx, MLX_KEY_DOWN))
		a->alpha -= 0.01;
	if (mlx_is_key_down(a->mlx, MLX_KEY_LEFT))
		a->beta += 0.01;
	if (mlx_is_key_down(a->mlx, MLX_KEY_RIGHT))
		a->beta -= 0.01;
	if (mlx_is_key_down(a->mlx, MLX_KEY_TAB))
		ft_print_map(a->map);
}

void	draw_something(t_a *a)
{
	int vector1[2]= {500, 500};
	int vector2[2]= {900, 900};
	ft_draw_line(vector1, vector2, a);
	int vector3[2]= {500, 500};
	int vector4[2]= {0, 0};
	ft_draw_line(vector4, vector3, a);
	int vector5[2]= {-500, -500};
	int vector6[2]= {685, 245};
	ft_draw_line(vector5, vector6, a);
}

void	hook(void *param)
{
	t_a	*a;
	a = param;

	ft_bzero(a->img->pixel, a->img->height * a->img->width * 4);
	ft_keyhook(a);
	ft_set_rot(a);
	draw_something(a);
	ft_img_calc(a);
}

void	ft_start(t_a *a)
{
	a->map = ft_get_map(a->fd);
	close(a->fd);
	ft_get_map_size(a);
	ft_init_map_xz(a);
	ft_set_rot(a);
	
	
	// debug
	ft_print_map(a->map);


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
		return (ft_exit(a), 0);

	// a->map = ft_get_map(a->fd);
	// ft_get_map_size(a);
	// ft_init_map_xz(a);
	// ft_print_map(a->map);
	// ft_set_rot(a);
	// printf("\n\n\n");
	// ft_print_map(a->map);
	// free(a);

	a->alpha = 30;
	a->beta = 30;
	a->gamma = 0;
	ft_start(a);
	printf("in main adress of rz: %p", &a->rz);

	a->alpha = 0;
	a->beta = 0;
	mlx_image_to_window(a->mlx, a->mlximg, 0, 0);
	mlx_loop_hook(a->mlx, &hook, a);
	mlx_loop(a->mlx);
	mlx_terminate(a->mlx);
	return (ft_exit(a), 0);
}
