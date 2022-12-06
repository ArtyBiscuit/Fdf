/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:44:04 by arforgea          #+#    #+#             */
/*   Updated: 2022/12/06 20:44:09 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include <stdio.h>
#include <fcntl.h>

static char	*get_file_data(char *path_file)
{
	int		fd;
	char	*buff;
	char	*str;

	buff = NULL;
	str = NULL;
	fd = open(path_file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (!buff)
	{
		buff = get_next_line(fd);
		if (!buff)
			break ;
		str = ft_secur_cat(str, buff);
		buff = NULL;
	}
	free(buff);
	close(fd);
	return (str);
}

t_point	*new_point(int x, int y, int z, int color)
{
	t_point *point;

	point = malloc(sizeof(t_point) * 1);
	if (!point)
		return (NULL);
	point->x = x;
	point->y = y;
	point->z = z;
	point->color = color;
	return (point);
}

int	is_num(char c)
{
	if (c <= 48 && c >= 57)
		return (1);
	return (0);
}

t_point	*get_data(char *data, int x, int y)
{
	t_point	*point;
	int	z;
	int	color;

	color = 0;
	while (*data == ' ')
		(*data)++;
	z = ft_atoi(data);
	while (is_num(*data))
		(*data)++;
	if (*data == ',')
		while(*data != ' ' || *data != '\n')
			(*data)++;
	point = new_point(x, y, z, color);
	return (point);
}

int main(void)
{
	t_point *point;
	char	*data;
	int		x;
	int		y;
	int i;

	i = 0;
	x = 0;
	y = 0;
	data = get_file_data("maps/test_maps/t2.fdf");
	while (data)
	{
		point = get_data(data, x, y);
		printf("X:%d Y:%d Z:%d\n", point->x, point->y, point->z);
	}
}















