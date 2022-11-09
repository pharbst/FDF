/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyaction_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:49:19 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/09 14:45:55 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	keyaction_rotation1(t_a *a)
{
	if (a->keys.w && !a->keys.s)
	{
		if (a->keys.shift)
			a->beta = 10;
		else
			a->beta = 1;
	}
	else if (a->keys.s && !a->keys.w)
	{
		if (a->keys.shift)
			a->beta = -10;
		else
			a->beta = -1;
	}
}

void	keyaction_rotation2(t_a *a)
{
	if (a->keys.q && !a->keys.e)
	{
		if (a->keys.shift)
			a->alpha = 10;
		else
			a->alpha = 1;
	}
	else if (a->keys.e && !a->keys.q)
	{
		if (a->keys.shift)
			a->alpha = -10;
		else
			a->alpha = -1;
	}
}

void	keyaction_rotation3(t_a *a)
{
		if (a->keys.d && !a->keys.a)
	{
		if (a->keys.shift)
			a->gamma = -10;
		else
			a->gamma = -1;
	}
	else if (a->keys.a && !a->keys.d)
	{
		if (a->keys.shift)
			a->gamma = 10;
		else
			a->gamma = 1;
	}
}
