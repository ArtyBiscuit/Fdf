/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:44:04 by arforgea          #+#    #+#             */
/*   Updated: 2022/12/08 17:34:37 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	get_y_size(char *data)
{
	int	y;
	int	index;

	y = 0;
	index = 0;
	while (data[index] != '\0')
	{
		if (data[index] == '\n')
			y++;
		index++;
	}
	return (y);
}

int	get_x_size(char *data)
{
	int	x;
	int	index;

	x = 0;
	index = 0;
	while (data[index] != '\n')
	{
		if (data[index] != ' ' && data[index] != '\n')
		{
			x++;
			while (data[index] != ' ' && data[index] != '\n')
				index++;
		}
		while (data[index] == ' ' && data[index] != '\n')
			index++;
	}
	return (x);
t_point ***map;}

t_point	***init_tab(char *data)
{
	t_point	***tab_point;
	int		size_x;
	int		size_y;
	int		i;

	i = 0;
	size_x = get_x_size(data);
	size_y = get_y_size(data);
	tab_point = malloc(sizeof(t_point **) * size_y);
	while (i < size_y)
	{
		tab_point[i] = malloc(sizeof(t_point *) * size_x);
		i++;
	}
	return (tab_point);
}

t_point	***get_matrix(char *data)
{
	t_point	***map;
	t_point	*point;

	map = init_tab(data);
	while (data)
	{
		point = get_point(&data);
		if (point == NULL)
			break ;
		map[(int)point->y][(int)point->x] = point;
	}
	return (map);
}

t_map	*get_map(char *path_file)
{
	t_map	*map;
	char	*data;

	data = get_file_data(path_file);
	map = malloc(sizeof(t_map) * 1);
	map->map = get_matrix(data);
	map->size_x = get_x_size(data);
	map->size_y = get_y_size(data);
	free(data);
	return (map);
}
