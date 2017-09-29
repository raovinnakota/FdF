/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_slopes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 13:07:27 by rvinnako          #+#    #+#             */
/*   Updated: 2017/09/26 17:59:11 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_straight(t_line *line, t_env *env)
{
	float	tmp;

	tmp = 0;
	if (line->y1 < line->y)
	{
		tmp = line->y;
		line->y = line->y1;
		line->y1 = tmp;
	}
	while (line->y <= line->y1)
	{
		mlx_pixel_put(env->mlx_ptr, env->win_ptr, line->x, line->y, env->color);
		(line->y++);
	}
}

void	draw_gradual(t_line *line, t_env *env)
{
	line->delta = fabsf(line->m);
	line->tmpy = line->y;
	if (line->x1 < line->x)
	{
		line->tmpx = line->x;
		line->x = line->x1;
		line->x1 = line->tmpx;
		line->tmpy = line->y1;
	}
	line->range = (line->x1 - line->x);
	while (line->x < line->x1)
	{
		mlx_pixel_put(env->mlx_ptr, env->win_ptr, line->x, line->tmpy, env->color);
		env->offset += line->delta;
		if (env->offset >= env->threshold)
		{
			line->tmpy += env->adjust;
			env->threshold += 1;
		}
		(line->x)++;
	}
}

void	draw_sharp(t_line *line, t_env *env)
{
	line->delta = fabsf(env->run / env->rise);
	line->tmpx = line->x;
	if (line->y1 < line->y)
	{
		line->tmpy = line->y;
		line->y = line->y1;
		line->y1 = line->tmpy;
		line->tmpx = line->x1;
	}
	line->range = (line->y1 - line->y);
	while (line->y < line->y1)
	{
		mlx_pixel_put(env->mlx_ptr, env->win_ptr, line->tmpx, line->y,
			env->color);
		env->offset += line->delta;
		if (env->offset >= env->threshold)
		{
			line->tmpx += env->adjust;
			env->threshold += 1;
		}
		line->y++;
	}
}

void	draw_down(t_env *env, t_line *line, t_point *p_list, t_point *p1)
{
	init_draw_down(env, line, p1, p_list);
	if (env->run == 0 && p1->cart_y + 1 < env->map->map_y)
		draw_straight(line, env);
	else
		draw_else(env, line);
	/*int j;
	int k;

	j = 0;
	while (j < env->map->map_x)
	{
		k = 0;
		while (k < env->map->map_y)
		{
			init_draw_down(env, j, k);
			if (env->run == 0 && j + 1 < env->len)
				draw_straight(env);
			else
				draw_else(env);
			k++;
		}
		j++;
	}*/
}

void	draw_right(t_env *env, t_line *line, t_point *p_list, t_point *p1)
{
	init_draw_right(env, line, p1, p_list);
	if (env->run == 0 && p1->cart_x + 1 < env->map->map_x)
		draw_straight(line, env);
	else
		draw_else(env, line);
	/*
	int j;
	int k;

	j = 0;
	while (j < env->len)
	{
		k = 0;
		while (k < env->width)
		{
			init_draw_right(env, j, k);
			if (env->run == 0 && k + 1 < env->len)
				draw_straight(env);
			else
				draw_else(env);
			k++;
		}
		j++;
	}
	*/
}
