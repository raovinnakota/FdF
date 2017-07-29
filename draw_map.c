/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 13:57:40 by rvinnako          #+#    #+#             */
/*   Updated: 2017/07/28 17:01:51 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_win	get_win(t_map *map, int scale)
{
	t_win	ret;

	ret.scale = scale;
	ret.win_x = ((map->map_x * ret.scale) + ret.scale);
	ret.win_y = ((map->map_y * ret.scale) + ret.scale);
	return (ret);
}

int		draw_map(void *mlx_ptr, void *win_ptr, t_point **p_list, t_win *win)
{
	int		z;

	z = 0;
	while (p_list[z])
	{
		if (p_list[z]->z == 10)
			mlx_pixel_put(mlx_ptr, win_ptr, (p_list[z]->x * win->scale), (p_list[z]->y * win->scale), 0xFFFFFF);
		else
			mlx_pixel_put(mlx_ptr, win_ptr, (p_list[z]->x * win->scale), (p_list[z]->y * win->scale), 0xFF00FF);
			z++;
	}
	return(0);
}


int		main(int ac, char **av)
{
	int		fd;
	t_win	winn;
	t_map	map;
	t_point	*p_list;
	void	*mlx;
	void	*win;
	char	**arr;

	if (ac < 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	arr = fill_map(fd);
	map = get_map(arr);
	p_list = point_list(&map);
	winn = get_win(&map, ft_atoi(av[2]));
	mlx = mlx_init();
	win = mlx_new_window(mlx, winn.win_x, winn.win_y, av[1]);
	draw_map(mlx, win, &p_list, &winn);
	mlx_loop(mlx);
}
