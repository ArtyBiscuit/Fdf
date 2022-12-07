/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:48:42 by arforgea          #+#    #+#             */
/*   Updated: 2022/12/07 17:56:15 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

t_point	*new_point(int x, int y, int z, int color)
{
	t_point	*point;

	point = malloc(sizeof(t_point) * 1);
	if (!point)
		return (NULL);
	point->x = (float)x;
	point->y = (float)y;
	point->z = (float)z;
	point->color = color;
	return (point);
}

t_point	*get_data(char **data, int x, int y)
{
	t_point	*point;
	int		z;
	int		color;

	color = 0;
	if (**data == '\0')
		return (NULL);
	while (**data == ' ')
		(*data)++;
	z = ft_atoi(*data);
	if (**data == '-')
		(*data)++;
	while (**data >= 48 && **data <= 57)
		(*data)++;
	if (**data == ',')
		while (**data != ' ' && **data != '\n')
			(*data)++;
	point = new_point(x, y, z, color);
	return (point);
}

char	*get_file_data(char *path_file)
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

t_point	*get_point(char **data)
{
	t_point		*point;
	static int	x;
	static int	y;

	if (!x && !y)
	{
		x = 0;
		y = 0;
	}
	point = get_data(data, x, y);
	x++;
	if (point == NULL)
		return (NULL);
	while (**data == ' ')
		(*data)++;
	if (**data == '\n')
	{
		y++;
		x = 0;
		(*data)++;
	}
	return (point);
}
