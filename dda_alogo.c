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

void	dda_algorithme(t_vars vars, float x0, float y0, float x1, float y1)
{
	float	dx;
	float	dy;
	float	x;
	float	y;
	float	steps;
	int		i;

	dx = x1 - x0;
	dy = y1 - y0;
    if (dx >= dy)
		steps = dx;
	else
		steps = dy;
	dx = dx/steps;
	dy = dy/steps;
	x = x0;
	y = y0;
	i = 1;
	while (i <= steps)
	{
		mlx_pixel_put(vars.mlx, vars.win, x, y, 100);
		x += dx;
		y += dy;
		i = i + 1;
    }
}  
