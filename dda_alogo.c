/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_alogo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:24:27 by arforgea          #+#    #+#             */
/*   Updated: 2022/12/09 15:28:56 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > WIN_SIZE_X || y < 0 || y > WIN_SIZE_Y)
		return ;
	dst = data->buff_pix + (y * data->line_size + x * (data->pix_bit / 8));
	*(unsigned int *)dst = color;
}

void	iso(t_point *point)
{
	point->x = ((point->x - point->y) * sin(0.6f)) + 800.0f;
	point->y = ((point->x + point->y) * sin(0.6f) - point->z) + 0.0f;
}

void	ft_zoom(t_point *start, t_point *end, float zoom)
{
	end->x *= zoom;
	end->y *= zoom;
	end->z *= zoom / 10.0f;
	start->x *= zoom;
	start->y *= zoom;
	start->z *= zoom / 10.0f;
}

void	dda(t_point start, t_point end, t_img *data, float zoom)
{
	float	d_y;
	float	d_x;
	float	steps;
	float	cmp;

	ft_zoom(&start, &end, zoom);
	iso(&start);
	iso(&end);
	d_y = end.y - start.y;
	d_x = end.x - start.x;
	steps = (float)fmax(fabs(d_x), fabs(d_y));
	d_x = d_x / steps;
	d_y = d_y / steps;
	cmp = 0.0f;
	while (++cmp <= steps)
	{
		pixel_put(data, start.x, start.y, start.color);
		start.x += d_x;
		start.y += d_y;
	}
	return ;
}
