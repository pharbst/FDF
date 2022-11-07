/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:31:51 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/03 16:25:25 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	init_map(t_a *a)
{
	ft_bzero(a->img->pixel, a->img->height * a->img->width * 4);
	a->map = read_map(a->fd);
	close(a->fd);
	map_size(a);
	init_map_coords(a);
}
