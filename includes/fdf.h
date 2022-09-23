/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 00:36:37 by pharbst           #+#    #+#             */
/*   Updated: 2022/09/17 01:48:13 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../MLX42/include/MLX42/MLX42.h"
# include <memory.h>
# include <libftio.h>

typedef	struct s_mapstruct
{
	struct s_maplist	*up;
	struct s_maplist	*down;
	struct s_maplist	*rightdown;
	struct s_maplist	*rightup;
	struct s_maplist	*leftdown;
	struct s_maplist	*leftup;
	int					y_offset;
}	t_mapstruct;

# define WIDTH 2600
# define HEIGHT 1600

int		main(void);

#endif
