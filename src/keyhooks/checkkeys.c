/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkkeys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:28:17 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/08 22:55:24 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	keyaction(t_a *a)
{
	keyaction_arrow(a);
	keyaction_rotation1(a);
	keyaction_rotation2(a);
	keyaction_special(a);
}

void	check_keys(t_a *a)
{
	a->old_keys = a->keys;
	keyhook_arrow(a);
	special_keyhook1(a);
	special_keyhook2(a);
	special_keyhook3(a);
	keyhook_num1(a);
	keyhook_num2(a);
	keyhook1(a);
	keyhook2(a);
	keyhook3(a);
	keyhook4(a);
	keyhook5(a);
	keyaction(a);
}