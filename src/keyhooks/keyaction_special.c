/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyaction_special.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:53:09 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/18 17:52:07 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	keyaction_special1(t_a *a)
{
	if (a->keys.space && !a->old_keys.space)
	{
		a->alpha = 0;
		a->beta = -45;
		a->gamma = 45;
		a->trans_x = 0;
		a->trans_y = 0;
		a->zoom = 1;
		reset_coords(a);
	}
	else if (a->keys.f1 && !a->old_keys.f1)
	{
		a->alpha = 0;
		a->beta = 0;
		a->gamma = 0;
		a->trans_x = 0;
		a->trans_y = 0;
		a->zoom = 1;
		reset_coords(a);
	}
}

void	keyaction_special2(t_a *a)
{
	if (a->keys.f2 && !a->old_keys.f2)
	{
		a->alpha = 0;
		a->beta = -90;
		a->gamma = 0;
		a->trans_x = 0;
		a->trans_y = 0;
		a->zoom = 1;
		reset_coords(a);
	}
	else if (a->keys.f3 && !a->old_keys.f3)
	{
		a->alpha = 0;
		a->beta = 0;
		a->gamma = 90;
		a->trans_x = 0;
		a->trans_y = 0;
		a->zoom = 1;
		reset_coords(a);
	}
}
