/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:08:10 by arforgea          #+#    #+#             */
/*   Updated: 2022/12/01 16:50:43 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	close(int key_code, t_vars *mlx_data)
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

int	main(void)
{
	t_vars	mlx_data;
	t_img	img;

	mlx_full_init(&mlx_data, WIN_SIZE_X, WIN_SIZE_Y, "MY FDF!");

	mlx_hook(mlx_data.win, 17, 0L, close, &mlx_data);
	mlx_loop(mlx_data.mlx);

	mlx_clear_window(mlx_data.mlx, mlx_data.win);
	mlx_destroy_window(mlx_data.mlx, mlx_data.win);
	mlx_destroy_display(mlx_data.mlx);
	free(mlx_data.mlx);
	exit(0);
}
