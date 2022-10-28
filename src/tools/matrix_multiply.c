/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:20:41 by pharbst           #+#    #+#             */
/*   Updated: 2022/10/28 16:26:43 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"



double	*ft_mat_multi(double **matrix, double *vector)
{
	double	*ret;

	ret = ft_calloc(4, sizeof(double));
	return (ret[0] = (matrix[0][0] * vector[0]) + (matrix[0][1] * vector[1])
	+ (matrix[0][2] * vector[2]) + (matrix[0][3] * vector[3]), ret[1] 
	= (matrix[1][0] * vector[0]) + (matrix[1][1] * vector[1]) + (matrix[1][2]
	* vector[2]) + (matrix[1][3] * vector[3]), ret[2] = (matrix[2][0] * vector[0])
	+ (matrix[2][1] * vector[1]) + (matrix[2][2] * vector[2]) + (matrix[2][3]
	* vector[3]), ret[3] = (matrix[3][0] * vector[0]) + (matrix[3][1] * vector[1])
	+ (matrix[3][2] * vector[2]) + (matrix[3][3] * vector[3]), ret);
}
