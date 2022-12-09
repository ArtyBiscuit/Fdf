/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:34:56 by arforgea          #+#    #+#             */
/*   Updated: 2022/12/09 17:31:20 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

#define MLX_ERROR 1
#define WIN_SIZE_X 1920
#define WIN_SIZE_Y 1080

typedef struct  s_vars t_vars;
typedef struct	s_img t_img;
typedef struct	s_point t_point;
typedef struct  s_map t_map;

struct	s_vars{
	void	*mlx;
	void	*win;
};

struct	s_img{
	void	*img;
	char	*buff_pix;
	int		endian;
	int		line_size;
	int		pix_bit;
};

struct	s_point{
	float	x;
	float	y;
	float	z;
	int		color;
};

struct	s_map{
	t_point ***map;
	int size_x;
	int size_y;
};

t_point *new_point(int x, int y, int z, int color);
void    dda(t_point start, t_point end, t_img *data, float mult);
void    pixel_put(t_img *data, int x, int y, int color);
t_point *get_data(char **data, int x, int y);
char    *get_file_data(char *path_file);
t_point *get_point(char **data);
int get_y_size(char *data);
int get_x_size(char *data);
t_point ***init_tab(char *data);
t_point ***get_matrix(char *data);
t_map   *get_map(char *path_file);
int mlx_close(t_vars *mlx_data);
int mlx_key(int keycode, t_vars *mlx_data);
void    free_all(t_map *map);
void    mlx_abort(t_vars mlx_data, t_img i);
#endif
