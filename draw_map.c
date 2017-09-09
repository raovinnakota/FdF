/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 13:57:40 by rvinnako          #+#    #+#             */
/*   Updated: 2017/09/08 18:03:48 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_win	get_win(t_map *map, int scale)
{
	t_win	ret;

	ret.scale = (float)scale;
	ret.win_x = ((map->map_x * ret.scale) + (5 * ret.scale));
	ret.win_y = ((map->map_y * ret.scale) + (5 * ret.scale));
	return (ret);
}

int		draw_map(void *mlx_ptr, void *win_ptr, t_win *win, t_map *map)
{
	t_point	*p_list;
	int		z;

	z = 0;
	p_list = point_list(map);
	rotate_graph(p_list, 0.100, map, 'x');
	rotate_graph(p_list, 0.500, map, 'z');
	while (z + 1 < map->map_area)
	{
		p_list[z].win_x = (p_list[z].x * win->scale * (-1)) + (win->win_x / 2);
		p_list[z].win_y = (p_list[z].y * win->scale * (-1)) + (win->win_y / 2);
		if ((int)p_list[z].z != 0)
			mlx_pixel_put(mlx_ptr, win_ptr, p_list[z].win_x, p_list[z].win_y, 0xFFFFFF);
		else
			mlx_pixel_put(mlx_ptr, win_ptr, p_list[z].win_x, p_list[z].win_y, 0xFF00FF);
		z++;
	}
	return(0);
}


int		main(int ac, char **av)
{
	int		fd;
	t_win	winn;
	t_map	map;
	void	*mlx;
	void	*win;
	char	**arr;

	if (ac < 3)
	{
		printf("You need to include scale\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	arr = fill_map(fd);
	map = get_map(arr);
	winn = get_win(&map, ft_atoi(av[2]));
	mlx = mlx_init();
	win = mlx_new_window(mlx, winn.win_x, winn.win_y, av[1]);
	draw_map(mlx, win, &winn, &map);
	mlx_loop(mlx);
}
