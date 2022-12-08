/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_alogo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:24:27 by arforgea          #+#    #+#             */
/*   Updated: 2022/12/07 20:02:32 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	**dda_algorithme(t_point *start, t_point *end/*, int **matric*/)
{
	float	d_y;
	float	d_x;
	int		steps;
	int		cmp;

	d_y = end->y - start->y;
	d_x = end->x - start->x;
	steps = (int)fmax(fabs(d_x), fabs(d_y));
	d_x = d_x / steps;
	d_y = d_y / steps;
	cmp = 1;
	while (cmp <= steps)
	{
		//matric[(int)start->y][(int)start->x] = 1;
		start->x += d_x;
		start->y += d_y;
		cmp++;
	}
	return (matric);
}
