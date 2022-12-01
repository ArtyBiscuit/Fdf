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

typedef struct	s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}				t_point;

int	**pars_map(char *map)
{
	int	descriptor;
	char *buff;
	char **t_map;

	descriptor = open(map, O_RDONLY);
	if (!descriptor)
		return (NULL);
	while ()
	{
		buff = get_next_line(descriptor);
		ft_strlen()
	}
}
