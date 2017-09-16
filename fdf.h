/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 17:18:31 by rvinnako          #+#    #+#             */
/*   Updated: 2017/09/15 15:42:35 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# include <limits.h>
# define sign(x) ((x > 0)?1:((x<0)?-1:0))

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
	int				mid_x;
	int				mid_y;
	int				map_area;
	int				hmin;
	int				hmax;
}					t_map;

typedef struct		s_win
{
	int				win_x;
	int				win_y;
	float			scale;
}					t_win;

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
	float			win_x;
	float			win_y;
	float			cart_x;
	float			cart_y;
}					t_point;



/*----parse.c----*/
char				**fill_map(int fd);

/*----set_map.c---*/
t_map				get_map(char **arr);

/*----point.c-----*/
t_point				new_point(int x, int y, int z);
t_point				find_right(t_point *point_list, t_point *point, t_map *map);
t_point				find_down(t_point *point_list, t_point *point, t_map *map);
t_point				*point_list(t_map *map);

/*----rotate.c----*/
void				rotate_graph(t_point *p_list, float angle, t_map *map, char axis);

/*----draw_line.c----*/
void				draw_line(t_point *p1, t_point *p2, void *mlx_ptr, void *win_ptr);

#endif
