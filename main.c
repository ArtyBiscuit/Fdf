/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:08:10 by arforgea          #+#    #+#             */
/*   Updated: 2022/12/08 20:31:06 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	mlx_close(int key_code, t_vars *mlx_data)
{
	(void) key_code;
	mlx_loop_end(mlx_data->mlx);
	return (0);
}

int mlx_full_init(t_vars *mlx_data, int size_x, int sixe_y, char *win_name)
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

#include <stdio.h>
t_map	*print_map(char *path, t_img *data)
{
	t_map *map;
	float mut = 50.0f;
	int	index;
	int i_x;
	int	i_y;

	i_x = 0;
	i_y = 0;
	index = 0;
	map = get_map(path);
	printf("w : %i, h : %i\n", map->size_x, map->size_y);
	while (i_y < map->size_y)
	{
		i_x = 0;
		while (i_x < map->size_x)
		{
			if (i_y < map->size_y - 1)
				dda_algorithme(*map->map[i_y][i_x], *map->map[i_y + 1][i_x], data, mut);
			if (i_x < map->size_x - 1)
				dda_algorithme(*map->map[i_y][i_x], *map->map[i_y][i_x + 1], data, mut);
			i_x++;
		}
		i_y++;
	}
	return (map);
}

int	main(void)
{
	t_vars	mlx_data;
	t_img	img;

	mlx_full_init(&mlx_data, WIN_SIZE_X, WIN_SIZE_Y, "MY FDF!");

	img.img = mlx_new_image(mlx_data.mlx, WIN_SIZE_X, WIN_SIZE_Y);
	img.buff_pix = mlx_get_data_addr(img.img, &img.pix_bit, &img.line_size, &img.endian);

	print_map("maps/test_maps/42.fdf", &img);	

	mlx_put_image_to_window(mlx_data.mlx, mlx_data.win, img.img, 0, 0);

	mlx_hook(mlx_data.win, 17, 0L, mlx_close, &mlx_data);
	mlx_loop(mlx_data.mlx);

	mlx_clear_window(mlx_data.mlx, mlx_data.win);
	mlx_destroy_window(mlx_data.mlx, mlx_data.win);
	mlx_destroy_display(mlx_data.mlx);
	free(mlx_data.mlx);
	exit(0);
}
