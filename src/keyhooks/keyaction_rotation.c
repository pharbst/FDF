/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyaction_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:49:19 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/11 14:18:43 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	stepsub10(double angel)
{
	if (angel != (int)angel)
	{
		if ((int)angel % 10 == 0)
			return ((int)angel);
		else
			return ((int)angel - ((int)angel % 10));
	}
	if ((int)angel % 10 == 0)
		return (angel - 10);
	else
		return ((int)angel - abs((int)angel % 10));
}

void	keyaction_rotation1(t_a *a)
{
	if (a->keys.ctrl && a->keys.w && !a->old_keys.w && !a->keys.s)
		a->beta += 10 - ((int)a->beta % 10);
	else if (a->keys.ctrl && a->keys.s && !a->old_keys.s && !a->keys.w)
		a->beta = (double)stepsub10(a->beta);
	else if (a->keys.w && !a->keys.s && !a->keys.ctrl)
	{
		if (a->keys.shift)
			a->beta += 10;
		else
			a->beta += 1;
	}
	else if (a->keys.s && !a->keys.w && !a->keys.ctrl)
	{
		if (a->keys.shift)
			a->beta -= 10;
		else
			a->beta -= 1;
	}
}

void	keyaction_rotation2(t_a *a)
{
	if (a->keys.ctrl && a->keys.q && !a->old_keys.q && !a->keys.e)
		a->alpha += 10 - ((int)a->alpha % 10);
	else if (a->keys.ctrl && a->keys.e && !a->old_keys.e && !a->keys.q)
		a->alpha = (double)stepsub10(a->alpha);
	else if (a->keys.q && !a->keys.e && !a->keys.ctrl)
	{
		if (a->keys.shift)
			a->alpha += 10;
		else
			a->alpha += 1;
	}
	else if (a->keys.e && !a->keys.q && !a->keys.ctrl)
	{
		if (a->keys.shift)
			a->alpha -= 10;
		else
			a->alpha -= 1;
	}
}

void	keyaction_rotation3(t_a *a)
{
	if (a->keys.ctrl && a->keys.a && !a->old_keys.a && !a->keys.d)
		a->gamma += 10 - ((int)a->gamma % 10);
	else if (a->keys.ctrl && a->keys.d && !a->old_keys.d && !a->keys.a)
		a->gamma = (double)stepsub10(a->gamma);
	else if (a->keys.d && !a->keys.a && !a->keys.ctrl)
	{
		if (a->keys.shift)
			a->gamma -= 10;
		else
			a->gamma -= 1;
	}
	else if (a->keys.a && !a->keys.d && !a->keys.ctrl)
	{
		if (a->keys.shift)
			a->gamma += 10;
		else
			a->gamma += 1;
	}
}
