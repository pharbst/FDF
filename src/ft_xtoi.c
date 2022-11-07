/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:22:46 by pharbst           #+#    #+#             */
/*   Updated: 2022/10/22 16:55:00 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

long	ft_xtoi(char *src)
{
	long	ret;

	if (!src)
		return(-1);
	if (!*src)
		return (0);
	if (src[0] != '0' && (src[1] != 'x' || src[1] != 'X'))
		return (-1);
	src += 2;
	ret = 0;
	while (*src)
	{
		if (ft_isdigit(*src))
			ret = (16 * ret) + (*src - '0');
		else if (*src >= 'a' && *src <= 'f')
			ret = (16 * ret) + (*src - ('a' - 10));
		else if (*src >= 'A' && *src <= 'F')
			ret = (16 * ret) + (*src - ('A' - 10));
		src++;
	}
	return (ret);
}
