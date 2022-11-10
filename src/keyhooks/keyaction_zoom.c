/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyaction_zoom.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 01:37:59 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/10 17:01:43 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	keyaction_zoom(t_a *a)
{
	if (a->keys.add && !a->keys.sub)
		a->zoom *= 1.1;
	else if (a->keys.sub && !a->keys.add)
		a->zoom *= 0.9;
}
