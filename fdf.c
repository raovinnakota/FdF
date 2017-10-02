/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 13:57:40 by rvinnako          #+#    #+#             */
/*   Updated: 2017/09/26 16:34:25 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
int		my_key_funct(int keycode, void *param)
{
	printf("key event %d\n", keycode);
}*/

void	set_points(t_env *env, t_point *p_list)
{
	//t_point	right;
	//t_point	down;
	int		z;

	z = 0;
	//p_list = point_list(map);
	rotate_graph(p_list, 0.7854 , env->map, 'z');
	rotate_graph(p_list, 0.0524, env->map, 'y');
	rotate_graph(p_list, 0.6982, env->map, 'x');
	while (z + 1 < env->map->map_area)
	{
		//printf("x:%fy:%f\n", p_list[z].cart_x, p_list[z].cart_y);
		p_list[z].win_x = (p_list[z].x * env->scale) + (env->win_x / 2);
		p_list[z].win_y = (p_list[z].y * env->scale) + (env->win_y / 2);
		//mlx_pixel_put(env->mlx_ptr, env->win_ptr, p_list[z].win_x, p_list[z].win_y, 0xFF00FF);
		z++;
	}
}


int		main(int ac, char **av)
{
	int		fd;
	t_map	map;
	t_env 	*env;
	t_line	line;
	t_point *p_list;
	char	**arr;

	if (ac < 2)
	{
		printf("Include the test map\n");
		return (0);
	}
	line = init_line();
	fd = open(av[1], O_RDONLY);
	arr = fill_map(fd);
	map = get_map(arr);
	env = init_env(&map);
	set_scale(env);
	//printf("%d\n", env->map->map[0][0]);
	p_list = point_list(env->map);
	//env->mlx_ptr = mlx_init();
	//env->win_ptr = mlx_new_window(env->mlx_ptr, env->win_x, env->win_y,
	//	"FDF Wireframe");
	//draw_map(env, p_list);
	//mlx_loop(env->mlx_ptr);
	//mlx_key_hook(env->win_ptr, my_key_funct, 0);
	draw_all(env, &line, p_list);
}
