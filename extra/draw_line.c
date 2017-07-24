/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 12:21:02 by rvinnako          #+#    #+#             */
/*   Updated: 2017/06/30 15:34:26 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line	new_line(x_start, y_start, x_end, y_end)
{
	t_line	new_line;

	new_line.x_start = x_start;
	new_line.y_start = y_start;
	new_line.x_end  = x_end;
	new_line.y_end = y_end;
	return (new_line);
}

int		get_slope(t_line line)
{
	int		rise;
	int		run;
	int		slope;

	rise = (line.y_end - line.y_start);
	run = (line.x_end - line.x_start);
	slope = rise/run;
	return (slope);
}


int		draw_line(void *mlx_ptr, void *win_ptr, t_line line)
{
	int	x;
	int	y;
	int	slope;

	slope = get_slope(line);
	while ((x != line.x_end) && (y != line.y_end))
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF00FF);
		y += slope;
		x += 1;
	}
	return (0);
}

int		main()
{
	void    *mlx;
	void    *win;
	t_line	nl;

	nl = new_line(0, 0, 133, 400);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	draw_line(mlx, win, nl);
	mlx_loop(mlx);
}
