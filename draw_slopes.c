/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_slopes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 13:07:27 by rvinnako          #+#    #+#             */
/*   Updated: 2017/09/18 17:42:27 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_straight(t_line *line, t_env env)
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
	line->delta = fabsf(line->m)
	line->tmpy = line->y;
	if (line->x1 < line->x)
	{
		line->tmpx = x;
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
