/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 17:18:31 by rvinnako          #+#    #+#             */
/*   Updated: 2017/09/26 17:19:07 by rvinnako         ###   ########.fr       */
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
	float			delta;
	float			tmpx;
	float			tmpy;
	float			range;
	float			x;
	float			y;
	float			x1;
	float			y1;
	float			m;
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

typedef struct		s_env
{
	int				win_x;
	int				win_y;
	float			scale;
	float			run;
	float			rise;
	float			offset;
	float			adjust;
	float			threshold;
	int				color;
	void			*mlx_ptr;
	void			*win_ptr;
	t_map			*map;
}					t_env;

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
	float			win_x;
	float			win_y;
	float			cart_x;
	float			cart_y;
	float			list_num; 
}					t_point;



/*----parse.c----*/
char				**fill_map(int fd);

/*----set_map.c---*/
t_map				get_map(char **arr);

/*----set_env.c---*/
t_env				*init_env(t_map *map);
void				set_scale(t_env *env);
t_line				init_line(void);

/*----point.c-----*/
t_point				new_point(int x, int y, int z);
t_point				find_right(t_point *point_list, t_point *point, t_map *map);
t_point				find_down(t_point *point_list, t_point *point, t_map *map);
//t_point				find_point(t_env *env, t_point *p_list, int j, int k);
t_point				*point_list(t_map *map);

/*----rotate.c----*/
void				rotate_graph(t_point *p_list, float angle, t_map *map, char axis);

/*----draw_line.c----*/
void				draw_all(t_env *env, t_line *line, t_point *p_list);
void				init_draw_right(t_env *env, t_line *line, t_point *p1, t_point *p_list);
void				init_draw_down(t_env *env, t_line *line, t_point *p1, t_point *p_list);
void				draw_else(t_env *env, t_line *line);

/*----draw_slopes.c--*/
void	draw_straight(t_line *line, t_env *env);
void	draw_gradual(t_line *line, t_env *env);
void	draw_sharp(t_line *line, t_env *env);
void	draw_down(t_env *env, t_line *line, t_point *p_list, t_point *p1);
void	draw_right(t_env *env, t_line *line, t_point *p_list, t_point *p1);

/*----fdf.c----------*/
void	set_points(t_env *env, t_point *p_list);
#endif
