/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 17:18:31 by rvinnako          #+#    #+#             */
/*   Updated: 2017/07/26 18:49:04 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# include <limits.h>

typedef struct		s_line
{
	int				x_start;
	int				y_start;
	int				x_end;
	int				y_end;
}					t_line;

typedef struct		s_map
{
	int				**map;
	int				map_x;
	int				map_y;
	int				map_area;
	//int				midx;
	//int				midy
	int				hmin;
	int				hmax;
}					t_map;

typedef struct		s_win
{
	int				win_x;
	int				win_y;
	int				scale;
}					t_win;

/*
typdef struct		s_env
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				h_min;
	int				h_max;
}					t_env;
*/

tydpef struct		s_point
{
	float			x;
	float			y;
	float			z;
}					t_point;


/*----parse.c----*/
char	**fill_map(int fd);

/*----set_map.c----*/
t_map	get_map(char **arr);

#endif
