/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:44:04 by arforgea          #+#    #+#             */
/*   Updated: 2022/12/01 17:52:37 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include <stdio.h>
#include <fcntl.h>

typedef struct	s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}				t_point;

void	pars_map(char *map)
{
	int	read_size;
	int	descriptor;
	char buff[1];
	char **t_map;

	read_size = 1;
	descriptor = open(map, O_RDONLY);
	if (!descriptor)
		return ;
	printf("Start !");
	while (read_size >= 1)
	{
		read_size = read(descriptor, buff, 1);
		if (!buff)
			return ;
		printf("%s", buff);
	}
	printf("%d", read_size);
}

int	main(void)
{
	pars_map("maps/test_maps/t1.fdf");
}
