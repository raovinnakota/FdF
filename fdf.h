/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 17:18:31 by rvinnako          #+#    #+#             */
/*   Updated: 2017/07/26 19:42:44 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define POINT_SIZE = sizeof(float) * 3;
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
