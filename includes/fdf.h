/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 00:36:37 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/02 20:14:36 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../MLX42/include/MLX42/MLX42.h"

# include <memory.h>
# include "libftio.h"
# include <stdio.h>
# include <math.h>

# define WIDTH 1000
# define HEIGHT 1000

typedef union s_pixel
{
	struct
	{
		char	r;
		char	g;
		char	b;
		char	a;
	};
	unsigned int	pixel;
}	t_pixel;

typedef struct s_img
{
	const unsigned int	width;
	const unsigned int	height;
	int					count;
	t_pixel				*pixel;
	mlx_instance_t		*instances;
	void				*context;
}	t_img;

typedef struct s_map
{
	struct s_map	*right;
	struct s_map	*down;
	struct s_map	*next;
	t_pixel			color;
	double				x;
	double				y;
	double				z;
	double				a_x;
	double				a_y;
	double				a_z;
	unsigned int		img_x;
	unsigned int		img_y;
} t_map;

typedef struct s_bre
{
	int				x0;
	int				x1;
	int				y0;
	int				y1;
	int				dx;
	int				dy;
	double			f;
	unsigned int	fd;
	unsigned int	sd;
} t_bre;

typedef struct s_a
{
	const unsigned int	map_x;
	const unsigned int	map_z;
	int					fd;
	double				**rx;		//roll
	double				**ry;		//yaw
	double				**rz;		//pitch
	double				alpha;		//roll
	double				beta;		//yaw
	double				gamma;		//roll
	mlx_t 				*mlx;
	mlx_image_t			*mlximg;
	t_img		 		*img;
	t_map				*map;
	t_pixel				color;
}t_a;

//betterlibft
char	**ft_better_split(char *src, char c);
char	*ft_better_trim(char *src, char *set);

//debug
void	ft_print_map(t_map *head);
void	printmatrix(double **matrix);

//image calc
void	ft_set_pixel(unsigned int x, unsigned int y, t_img *img, unsigned int color);
void 	draw(t_a *a);
void	ft_img_calc(t_a *a);
void	ft_draw_line(int *vector1,  int *vector2, t_a *a);

//main
int		main(int argc, char **argv);
void	ft_init_t_a(t_a *a);
t_img	*ft_init_img(mlx_image_t *mlximg);

//maptools
t_map	*ft_get_map(int fd);
void	ft_get_map_size(t_a *a);
void	ft_init_map_xz(t_a *a);

//tools
long	ft_xtoi(char *src);
double	*ft_mat_multi(double **matrix, double *vector);
void	ft_rotate(char *flag, t_a *a);
void	ft_set_rot(t_a *a);
void	ft_exit(t_a *a);


#endif
