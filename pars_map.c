/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:44:04 by arforgea          #+#    #+#             */
/*   Updated: 2022/12/05 17:19:39 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include <stdio.h>
#include <fcntl.h>

static char	*get_file_data(char *path_map)
{
	int		descriptor;
	int		read_size;
	char	*tmp;
	char	*map;

	map = NULL;
	tmp = NULL;
	read_size = 1;
	descriptor = open(path_map, O_RDONLY);
	if (descriptor < 0)
		return (NULL);
	while (read_size)
	{
		tmp = ft_calloc(200+1, 1);
		read_size = read(descriptor, tmp, 200);
		if (!read_size)
			break;
		map = ft_secur_cat(map, tmp);
	}
	free(tmp);
	close(descriptor);
	return (map);
}

static int	get_line(char *map)
{
	int	cmp;
	int	line;

	cmp = -1;
	line = 0;
	while (map[cmp++])
		if (map[cmp] == '\n')
			line++;
	return (line);
}
static int get_column(char *map)
{
	int	cmp;
	int	bol;
	int	column;

	cmp = 0;
	bol = 0;
	column = 0;
	while (map[cmp] && map[cmp] != '\n')
	{
		if (map[cmp] == ' ')
			column++;
		cmp++;
	}
	return (column);
}

static t_map	init_struct_map(char *map)
{
	t_point **tab;
	t_map	final_map;

	int cmp;	
	int	line;
	int	column;

	if (!map)
		return (NULL);
	cmp = -1;
	line = get_line(map);
	column = get_column(map);
	tab = malloc(sizeof(t_point *) * line);
	while(cmp++ < line)
		tab[cmp] = malloc(sizeof(t_point) * column);
	final_map->map = tab;
	final_map->size_x = column;
	final_map->size_y = line;
	return (final_map);
}

t_map	parse_map(char *path_map)
{
	int		index;
	char	*hard_data;
	t_map	map;

	index = 0;
	hard_data = get_file_data(path_map);
	map = init_struct_map(hard_data);
	while (hard_data[index])
	{
		
	}
}
