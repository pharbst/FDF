/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:09:40 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/03 16:10:33 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_up(t_a *a)
{
	a->alpha = 1;
}

void	ft_down(t_a *a)
{
	a->alpha = -1;
}

void	ft_left(t_a *a)
{
	a->beta = 1;
}

void	ft_right(t_a *a)
{
	a->beta = -1;
}
