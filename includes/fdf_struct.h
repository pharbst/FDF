/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:08:16 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/09 17:52:32 by pharbst          ###   ########.fr       */
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
	const int			width;
	const int			height;
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
	double			x;
	double			y;
	double			z;
	double			a_x;
	double			a_y;
	double			a_z;
	unsigned int	img_x;
	unsigned int	img_y;
}	t_map;

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
}	t_bre;

typedef struct s_rm
{
	unsigned int	i;
	t_map			*head;
	t_map			*node;
	t_map			*next;
	t_map			*topnode;
	char			**line;
	char			**var;
}	t_rm;

typedef struct s_keys
{
	bool	shift;
	bool	space;
	bool	alt;
	bool	ctrl;
	bool	tab;
	bool	f1;
	bool	f2;
	bool	f3;
	bool	f4;
	bool	f5;
	bool	f6;
	bool	up;
	bool	down;
	bool	left;
	bool	right;
	bool	add;
	bool	sub;
	bool	num_1;
	bool	num_2;
	bool	num_3;
	bool	num_4;
	bool	num_5;
	bool	num_6;
	bool	num_7;
	bool	num_8;
	bool	num_9;
	bool	num_0;
	bool	q;
	bool	w;
	bool	e;
	bool	r;
	bool	t;
	bool	y;
	bool	u;
	bool	i;
	bool	o;
	bool	p;
	bool	a;
	bool	s;
	bool	d;
	bool	f;
	bool	g;
	bool	h;
	bool	j;
	bool	k;
	bool	l;
	bool	z;
	bool	x;
	bool	c;
	bool	v;
	bool	b;
	bool	n;
	bool	m;
} t_keys;

typedef struct s_a
{
	const unsigned int	map_x;
	const unsigned int	map_z;
	int					fd;
	int					x_offset;
	int					y_offset;
	int					z_offset;
	int					zoom;
	int 				trans_x;
	int					trans_y;
	double				alpha;		//roll
	double				beta;		//pitch
	double				gamma;		//yaw
	double				**rx;		//roll
	double				**ry;		//yaw
	double				**rz;		//pitch
	t_keys				keys;
	t_keys				old_keys;
	mlx_t 				*mlx;
	mlx_image_t			*mlximg;
	t_img		 		*img;
	t_map				*map;
	t_pixel				color;
}t_a;

#endif