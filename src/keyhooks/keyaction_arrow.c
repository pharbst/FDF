/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyaction_arrow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:40:38 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/08 22:10:56 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	keyaction_arrow(t_a *a)
{
	if (a->keys.up && !a->keys.down)
		if (a->keys.shift)
			a->trans_y -= 10;
		else
			a->trans_y -= 1;
	else if (a->keys.down && !a->keys.up)
		if (a->keys.shift)
			a->trans_y += 10;
		else
			a->trans_y += 1;
	if (a->keys.right && !a->keys.left)
		if (a->keys.shift)
			a->trans_x += 10;
		else
			a->trans_x += 1;
	else if (a->keys.left && !a->keys.right)
		if (a->keys.shift)
			a->trans_x -= 10;
		else
			a->trans_x -= 1;
}
