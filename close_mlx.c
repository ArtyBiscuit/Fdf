/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:46:10 by arforgea          #+#    #+#             */
/*   Updated: 2022/12/09 17:56:59 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	mlx_close(t_vars *mlx_data)
{
	mlx_loop_end(mlx_data->mlx);
	return (0);
}

int	mlx_key(int keycode, t_vars *mlx_data)
{
	if (keycode == 65307)
		mlx_close(mlx_data);
	return (0);
}

void	free_all(t_map *map)
{
	int	i_x;
	int	i_y;

	i_x = 0;
	i_y = 0;
	while (i_y < map->size_y)
	{
		i_x = 0;
		while (i_x < map->size_x)
		{
			free(map->map[i_y][i_x]);
			i_x++;
		}
		free(map->map[i_y]);
		i_y++;
	}
	free(map->map);
	free(map);
}

void	mlx_abort(t_vars mlx_data, t_img i)
{
	mlx_destroy_image(mlx_data.mlx, i.img);
	mlx_destroy_window(mlx_data.mlx, mlx_data.win);
	mlx_destroy_display(mlx_data.mlx);
	free(mlx_data.mlx);
	write(2, "Error!\n", 7);
}
