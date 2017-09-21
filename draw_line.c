/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:05:21 by rvinnako          #+#    #+#             */
/*   Updated: 2017/09/20 16:51:27 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_all(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->w_wid, env->w_len,
		"FDF Wireframe");
	draw_right(env);
	draw_down(env);
	mlx_loop(env->mlx);
}

void		init_draw_right(t_env *env, int j, int k)
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

void		draw_else(t_env *env)
{
	line->m = env->rise / env->run;
	env->adjust = line->m >= 0 ? 1 : -1;
	env->offset = 0;
	env->threshold = 0.5;
	if (line->m <= 1 && line->m >= -1)
		draw_gradual(env);
	else
		draw_sharp(env);
}
