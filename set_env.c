/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 18:05:40 by rvinnako          #+#    #+#             */
/*   Updated: 2017/09/26 16:32:32 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_env	*init_env(t_map *map)
{
	t_env	*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->win_x = 600;
	env->win_y = 600;
	env->scale = 0;
	env->run = 0;
	env->rise = 0;
	env->offset = 0;
	env->adjust = 0;
	env->threshold = 0;
	env->color = 0xFFFFFF;
	env->mlx_ptr = NULL;
	env->win_ptr = NULL;
	env->map = map;
	return (env);
}

void	set_scale(t_env *env)
{
	int scale;

	scale = 400 / env->map->map_x;
	env->scale = scale;
}

/*
void	set_map(t_env *env, t_map *map)
{
	env->map = map;
}
*/
t_line init_line(void)
{
	t_line line;

	line.delta = 0;
	line.tmpx = 0;
	line.tmpy = 0;
	line.range = 0;
	line.x = 0;
	line.y = 0;
	line.x1 = 0;
	line.y1 = 0;
	line.m = 0;

	return (line);
}
