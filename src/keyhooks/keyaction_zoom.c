/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyaction_zoom.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 01:37:59 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/10 17:06:58 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	keyaction_zoom(t_a *a)
{
	if (a->keys.add && !a->keys.sub)
	{
		if (a->keys.shift)
			a->zoom *= 1.005;
		else
			a->zoom *= 1.1;
	}
	else if (a->keys.sub && !a->keys.add)
	{
		if (a->keys.shift)
			a->zoom *= 0.995;
		else
			a->zoom *= 0.9;
	}
}
