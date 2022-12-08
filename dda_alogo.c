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

static void	float_swap(float *arg1, float *arg2)
{
	float	tmp;

	tmp = *arg1;
	*arg1 = *arg2;
	*arg2 = tmp;
}

static void	cheak_swap(t_point *start, t_point *end)
{
	if (start->x < end->x)
	{
		float_swap(&start->x, &end->x);
		float_swap(&start->y, &end->y);
	}
	if (start->x > end->x)
	{
		float_swap(&start->x, &end->x);
		float_swap(&start->y, &end->y);
	}
}

int	**dda_algorithme(t_point *start, t_point *end/*, int **matric*/)
{
	float	d_y;
	float	d_x;
	float	steps;
	int		cmp;

	cheak_swap(start, end);
	d_y = end->y - start->y;
	d_x = end->x - start->x;
	if (d_x >= d_y)
		steps = d_x;
	else
		steps = d_y;
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
