/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:08:16 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/06 19:11:47 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H

# include "fdf.h"
# include "MLX42/MLX42.h"
# include "libftio.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# include <math.h>
# include <stdbool.h>

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
	unsigned int	dx;
	unsigned int	dy;
	double			f;
	unsigned int	fd;
	unsigned int	sd;
} t_bre;

typedef struct s_keys
{
	bool	shift;
	bool	space;
} t_keys;

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
	t_keys				*keys;
	mlx_t 				*mlx;
	mlx_image_t			*mlximg;
	t_img		 		*img;
	t_map				*map;
	t_pixel				color;
}t_a;

#endif