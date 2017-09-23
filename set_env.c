/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 18:05:40 by rvinnako          #+#    #+#             */
/*   Updated: 2017/09/22 17:23:44 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		init_scale(t_map *map)
{
	int scale;

	scale = 400 / map->map_x;
	return (scale);
}

t_env	*init_env(t_map *map)
{
	t_env	*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->win_x = 600;
	env->win_y = 600;
	env->scale = init_scale(map);
	env->run = 0;
	env->rise = 0;
	env->offset = 0;
	env->adjust = 0;
	env->threshold = 0;
	env->color = 0xFFFFFF;
	env->mlx_ptr = NULL;
	env->win_ptr = NULL;
	env->map = NULL;
	return (env);
}
