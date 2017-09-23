/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:05:21 by rvinnako          #+#    #+#             */
/*   Updated: 2017/09/22 17:26:35 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_all(t_env *env, t_line *line, t_point *p1, t_point *p2)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->w_wid, env->w_len,
		"FDF Wireframe");
	draw_right(env, line, p1, p2);
	draw_down(env, line, p1, p2);
	mlx_loop(env->mlx);
}

void	init_draw_right(t_env *env, t_line *line, t_point *p1, t_point *p2)
{
	if (p1->cart_x < env->map->map_x)
	{
		line->x0 = round(p1->cart_x);
		line->y0 = round(p1->cart_y);
		line->x1 = round(p2->cart_x);
		line->x2 = round(p2->cart_y);
		env->run = line->x1 - line->x0;
		env->rise = line->y1 - line->y1;
	}
}

void	init_draw_down(t_env *env, t_line *line, t_point *p1, t_point *p2)
{
	if (p1->cart_y < env->map->)
	{
		line->x0 = round(p1->cart_x);
		line->y0 = round(p1->cart_y);
		line->x1 = round(p2->cart_x);
		line->x2 = round(p2->cart_y);
		env->run = line->x1 - line->x0;
		env->rise = line->y1 - line->y1;
	}
}
/*
void		init_draw_right(t_env *env, t_line int j, int k)
{
	if (k + 1 < env->width)
	{
		line->x = round(env->points[j][k].x);
		line->x1 = round(env->points[j][k + 1].x);
		line->y = round(env->points[j][k].y);
		line->y1 = round(env->points[j][k + 1].y);
		env->run = line->x1 - line->x;
		env->rise = line->y1 - line->y;
	}
}

void		init_draw_down(t_env *env, int j, int k)
{
	if (j + 1 < env->len)
	{
		line->x = round(env->points[j][k].x);
		line->x1 = round(env->points[j + 1][k].x);
		line->y = round(env->points[j][k].y);
		line->y1 = round(env->points[j + 1][k].y);
		env->run = line->x1 - line->x;
		env->rise = line->y1 - line->y;
	}
}
*/
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
