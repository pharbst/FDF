/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 00:36:37 by pharbst           #+#    #+#             */
/*   Updated: 2022/10/17 16:29:33 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../MLX42/include/MLX42/MLX42.h"

# include <memory.h>
# include <libftio.h>
# include <stdio.h>

//	union for pixel color
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
	const unsigned int	height;
	const unsigned int	width;
	int					count;
	t_pixel				*pixel;
	mlx_instance_t		*instance;
	void				*context;
}	t_img;

typedef struct s_map
{
	struct s_map	*right;
	struct s_map	*down;
	struct s_map	*next;
	t_pixel			color;
	int				y;
} t_map;

# define WIDTH 2600
# define HEIGHT 1600

int		main(int argc, char **argv);
char	**ft_better_split(char const *src, char c);
t_map	*ft_get_map(int fd);
long	ft_xtoi(char *src);
void	ft_print_map(t_map *head);
void	ft_set_pixel(unsigned int x, unsigned int y, t_img *img, unsigned int color);
void	ft_get_map_size(unsigned int *x, unsigned int *y, t_map *head);
char	*ft_better_trim(char *src, char *set);

#endif
