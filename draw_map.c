/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 13:57:40 by rvinnako          #+#    #+#             */
/*   Updated: 2017/08/03 16:48:33 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_win	get_win(t_map *map, int scale)
{
	t_win	ret;

	ret.scale = (float)scale;
	ret.win_x = ((map->map_x * ret.scale) + (ret.scale));
	ret.win_y = ((map->map_y * ret.scale) + (ret.scale));
	return (ret);
}

int		draw_map(void *mlx_ptr, void *win_ptr, t_win *win, t_map *map)
{
	int		z;
	t_point	*p_list;

	z = 0;
	p_list = point_list(map);
	//rotate_graph(&p_list, 2.094, 'x', map);
	/*rotate_graph(&p_list, 2.094, 'y', map);
	rotate_graph(&p_list, 2.094, 'z', map);*/
	while (z + 1 < map->map_area)
	{
		if ((int)p_list[z].z == 10)
			mlx_pixel_put(mlx_ptr, win_ptr, p_list[z].x * win->scale, p_list[z].y * win->scale, 0xFFFFFF);
		else
			mlx_pixel_put(mlx_ptr, win_ptr, p_list[z].x * win->scale, p_list[z].y * win->scale, 0xFF00FF);
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

	if (ac < 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	arr = fill_map(fd);
	map = get_map(arr);
	winn = get_win(&map, ft_atoi(av[2]));
	mlx = mlx_init();
	win = mlx_new_window(mlx, winn.win_x, winn.win_y, av[1]);
	draw_map(mlx, win, &winn, &map);
	mlx_loop(mlx);
}
