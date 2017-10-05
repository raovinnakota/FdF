/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:05:21 by rvinnako          #+#    #+#             */
/*   Updated: 2017/09/26 17:59:13 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_all(t_env *env, t_line *line, t_point *p_list)
{
	int		z;

	z = 0;
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, env->win_x, env->win_y,
		"FDF Wireframe");
	set_points(env, p_list);
	while (z < env->map->map_area)
	{
		draw_right(env, line, p_list, &p_list[z]);
		draw_down(env, line, p_list, &p_list[z]);
		z++;
	}
	mlx_key_hook(env->win_ptr, my_key_funct, 0); //(key_event_53)
	mlx_loop(env->mlx_ptr);
}

void	init_draw_right(t_env *env, t_line *line, t_point *p1, t_point *p_list)
{
	t_point p2;

	p2 = p_list[(int)p1->list_num + 1];
	if (p1->cart_x + 1 < env->map->map_x)
	{
		line->x = round(p1->win_x);
		line->y = round(p1->win_y);
		line->x1 = round(p2.win_x);
		line->y1 = round(p2.win_y);
		env->run = line->x1 - line->x;
		env->rise = line->y1 - line->y;
	}
}

void	init_draw_down(t_env *env, t_line *line, t_point *p1, t_point *p_list)
{
	t_point p2;

	p2 = p_list[(int)p1->list_num + env->map->map_x];
	if (p1->cart_y + 1 < env->map->map_y)
	{
		line->x = round(p1->win_x);
		line->y = round(p1->win_y);
		line->x1 = round(p2.win_x);
		line->y1 = round(p2.win_y);
		env->run = line->x1 - line->x;
		env->rise = line->y1 - line->y;
	}
}

void		draw_else(t_env *env, t_line *line)
{
	line->m = env->rise / env->run;
	env->adjust = line->m >= 0 ? 1 : -1;
	env->offset = 0;
	env->threshold = 0.5;
	if (line->m <= 1 && line->m >= -1)
		draw_gradual(line, env);
	else
		draw_sharp(line, env);
}
