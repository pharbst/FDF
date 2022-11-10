/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peter <peter@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:41:25 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/10 02:16:34 by peter            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "fdf_struct.h"
# include "MLX42/MLX42.h"
# include "libftio.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# include <math.h>
# include <stdbool.h>

# include <stdio.h>

# define WIDTH 1000
# define HEIGHT 1000


//img
void	draw_line(unsigned int vector1[2], unsigned int vector2[2], t_a *a, unsigned int color);
void	get_img_coords(t_a *a);
void	img_draw(t_a *a);
void	offset(t_a *a);
void	recalc_img(t_a *a);
void	rotate(char *flag, t_a *a);
void	set_pixel(unsigned int x, unsigned int y, t_img *img, unsigned int color);

//init
void	img_init(t_a *a);
void	init_map_coords(t_a *a);
void	init_map(t_a *a);
void	init_matrix(t_a *a);
void	t_a_init(t_a *a);

//keyhooks
void	check_keys(t_a *a);
void	keyaction_arrow1(t_a *a);
void	keyaction_arrow2(t_a *a);
void	keyaction_rotation1(t_a *a);
void	keyaction_rotation2(t_a *a);
void	keyaction_rotation3(t_a *a);
void	keyaction_special(t_a *a);
void	keyaction_y(t_a *a);
void	keyaction_zoom(t_a *a);
void	keyhook_arrow(t_a *a);
void	keyhook_num1(t_a *a);
void	keyhook_num2(t_a *a);
void	special_keyhook1(t_a *a);
void	special_keyhook2(t_a *a);
void	special_keyhook3(t_a *a);
void	keyhook1(t_a *a);
void	keyhook2(t_a *a);
void	keyhook3(t_a *a);
void	keyhook4(t_a *a);
void	keyhook5(t_a *a);

//tools
void	free_map(t_a *a);
char	**ft_better_split(char *src, char c);
char	*ft_better_trim(char *src, char *set);
void	ft_exit(t_a *a);
long	ft_xtoi(char *src);
void	map_size(t_a *a);
double	*mat_multi(double **matrix, double *vector);
t_map	*read_map(int fd);
void	reset_coords(t_a *a);
void	ft_print_map(t_map *head);

//main
int		main(int argc, char **argv);

#endif