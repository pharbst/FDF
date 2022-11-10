/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:49:51 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/10 01:51:28 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_struct.h"

mlx_image_t	*g_img;

void	hook(void *param)
{
	t_a	*a;

	a = (t_a *)param;
	check_keys(a);
	recalc_img(a);
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
	a->gamma = 45;
	a->beta = -45;
	a->alpha = -0;
	recalc_img(a);
	mlx_image_to_window(a->mlx, a->mlximg, 0, 0);
	mlx_loop_hook(a->mlx, &hook, a);
	mlx_loop(a->mlx);
	mlx_terminate(a->mlx);
	ft_exit(a);
}
