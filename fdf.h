/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:34:56 by arforgea          #+#    #+#             */
/*   Updated: 2022/12/05 17:17:45 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

#define MLX_ERROR 1
#define WIN_SIZE_X 600
#define WIN_SIZE_Y 600

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
	t_point **map;
	int size_x;
	int size_y;
};
#endif
