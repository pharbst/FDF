/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additionnal_keys.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:56:17 by pharbst           #+#    #+#             */
/*   Updated: 2022/11/06 20:15:30 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	set_to_default(t_a *a)
{
	printf("set to default");
}

void	ft_space(t_a *a)
{
	set_to_default(a);	
}

void	ft_tab(t_a *a)
{
	ft_print_map(a->map);
}