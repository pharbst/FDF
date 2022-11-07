/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:41:25 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/06 20:20:42 by pharbst          ###   ########.fr       */
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

void	ft_tab(t_a *a);
void	ft_space(t_a *a);
void	ft_up(t_a *a);
void	ft_down(t_a *a);
void	ft_left(t_a *a);
void	ft_right(t_a *a);
void	ft_draw_line(int *vector1, int *vector2, t_a *a);
void	free_map(t_a *a);
char	**ft_better_split(char *src, char c);
char	*ft_better_trim(char *src, char *set);
void	ft_exit(t_a *a);
void	ft_img_calc(t_a *a);
void	ft_rotate(char *flag, t_a *a);
void	ft_set_pixel(unsigned int x, unsigned int y, t_img *img, unsigned int color);
long	ft_xtoi(char *src);
void	img_init(t_a *a);
void	init_map_coords(t_a *a);
void	init_map(t_a *a);
void	init_matrix(t_a *a);
void	ft_keyhook(t_a *a);
void	ft_addkeyhook(t_a *a);
int		main(int argc, char **argv);
void	map_size(t_a *a);
t_map	*read_map(int fd);
double	*ft_mat_multi(double **matrix, double *vector);
void	t_a_init(t_a *a);
void	ft_w(t_a *a);
void	ft_a(t_a *a);
void	ft_s(t_a *a);
void	ft_d(t_a *a);

void	ft_print_map(t_map *head);

#endif