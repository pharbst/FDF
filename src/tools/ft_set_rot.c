/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:46:48 by pharbst           #+#    #+#             */
/*   Updated: 2022/10/28 17:54:42 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_set_rot(t_a *a)
{
	ft_rotate("roll", a);
	ft_rotate("yaw", a);
	ft_rotate("pitch", a);
	//ft_translate(a);
}
