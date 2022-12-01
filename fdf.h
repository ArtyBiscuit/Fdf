/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:34:56 by arforgea          #+#    #+#             */
/*   Updated: 2022/12/01 16:43:56 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include "mlx/mlx.h"
# include "get_next_line.h"

#define MLX_ERROR 1
#define WIN_SIZE_X 600
#define WIN_SIZE_Y 600

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_img{
	void	*img;
	char	*buff_pix;
	int		endian;
	int		line_size;
	int		pix_bit;
}				t_img;
#endif
