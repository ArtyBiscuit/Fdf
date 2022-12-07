/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:52:48 by arforgea          #+#    #+#             */
/*   Updated: 2022/12/07 18:24:10 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include <stdio.h>

int main(void)
{
	t_map *map;

	int x = 12;
	int y = 10;
	map = get_map("maps/test_maps/42.fdf");
	printf("index:%d/%d | X=%f Y=%f Z=%f\n", x, y, map->map[y][x]->x, map->map[y][x]->y, map->map[y][x]->z);
}


while (y < y_max)
{
	x= 0;
	while (x < x_max)
	{
		if (x < x_max-1)
			dda(x, y, x + 1, y);
		if (y < y_max-1)	
			dda(x, y, x , y + 1);
		x++;
	}
y++;
}
