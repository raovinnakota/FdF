/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 17:18:31 by rvinnako          #+#    #+#             */
/*   Updated: 2017/07/16 15:50:38 by rvinnako         ###   ########.fr       */
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

typdef struct		s_env
{
	int				map_x;
	int				map_y;
	int				map_area;
	int				scale;
	int				h_min;
	int				h_max;
}					t_env;

tydef struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

/*----parse.c----*/
char	**fill_map(int fd);

/*----set_map.c----*/

#endif
