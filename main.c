/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:08:10 by arforgea          #+#    #+#             */
/*   Updated: 2022/12/09 18:11:49 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	mlx_full_init(t_vars *mlx_data, int size_x, int sixe_y, char *win_name)
{
	mlx_data->mlx = mlx_init();
	if (mlx_data->mlx == NULL)
		return (MLX_ERROR);
	mlx_data->win = mlx_new_window(mlx_data->mlx, size_x, sixe_y, win_name);
	if (mlx_data->win == NULL)
	{
		free(mlx_data->mlx);
		return (MLX_ERROR);
	}
	return (0);
}

void	print_map(t_map *map, t_img *data, float zoom)
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
			if (i_y < map->size_y - 1)
				dda(*map->map[i_y][i_x], *map->map[i_y + 1][i_x], data, zoom);
			if (i_x < map->size_x - 1)
				dda(*map->map[i_y][i_x], *map->map[i_y][i_x + 1], data, zoom);
			i_x++;
		}
		i_y++;
	}
}

t_map	*put_map(char *path, float zoom, t_img *data)
{
	t_map	*map;

	map = get_map(path);
	if (map == NULL)
		return (NULL);
	print_map(map, data, zoom);
	return (map);
}

char	*chek_input(int arg1, char **arg2)
{
	char *path;

	if (arg1 != 2)
		return (NULL);	
	return (arg2[1]);
}

int	main(int argc, char **argv)
{
	t_vars	mlx_data;
	t_img	i;
	t_map	*map;

	mlx_full_init(&mlx_data, WIN_SIZE_X, WIN_SIZE_Y, "MY FDF!");
	i.img = mlx_new_image(mlx_data.mlx, WIN_SIZE_X, WIN_SIZE_Y);
	i.buff_pix = mlx_get_data_addr(i.img, &i.pix_bit, &i.line_size, &i.endian);
	map = put_map(chek_input(argc, argv), 40.0, &i);
	if (map == NULL)
	{
		mlx_abort(mlx_data, i);
		return (1);
	}
	mlx_put_image_to_window(mlx_data.mlx, mlx_data.win, i.img, 0, 0);
	mlx_hook(mlx_data.win, 17, 0L, mlx_close, &mlx_data);
	mlx_hook(mlx_data.win, 2, 1L, mlx_key, &mlx_data);
	mlx_loop(mlx_data.mlx);
	free_all(map);
	mlx_destroy_image(mlx_data.mlx, i.img);
	mlx_clear_window(mlx_data.mlx, mlx_data.win);
	mlx_destroy_window(mlx_data.mlx, mlx_data.win);
	mlx_destroy_display(mlx_data.mlx);
	free(mlx_data.mlx);
	exit(0);
}
