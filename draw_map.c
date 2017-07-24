/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 13:57:40 by rvinnako          #+#    #+#             */
/*   Updated: 2017/07/24 15:49:07 by rvinnako         ###   ########.fr       */
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

int		draw_map(void *mlx_ptr, void *win_ptr, t_map *map, t_win *win)
{
	int		x;
	int		y;

	y = 1;
	while (y <= map->map_y)
	{
		x = 1;
		ft_putchar('\n');
		while (x <= map->map_x)
		{
			if(map->map[y-1][x-1] == 10)
				mlx_pixel_put(mlx_ptr, win_ptr, (x * win->scale), (y * win->scale), 0xFFFFFF);
			else
				mlx_pixel_put(mlx_ptr, win_ptr, (x * win->scale), (y * win->scale), 0xFF00FF);
			x++;
		}
		y++;
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
	draw_map(mlx, win, &map, &winn);
	mlx_loop(mlx);
}
