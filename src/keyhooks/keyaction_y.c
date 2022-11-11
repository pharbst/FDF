/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyaction_y.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 02:13:23 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/10 17:17:02 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	keyaction_y(t_a *a)
{
	if (a->keys.z && !a->keys.x)
	{
		if (a->keys.shift)
			a->y_scale *= 1.005;
		else
			a->y_scale *= 1.05;
	}
	else if (a->keys.x && !a->keys.z)
	{
		if (a->keys.shift)
			a->y_scale *= 0.995;
		else
			a->y_scale *= 0.95;
	}
}
