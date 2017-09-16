/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:05:21 by rvinnako          #+#    #+#             */
/*   Updated: 2017/09/15 16:45:44 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//#include <graphics.h>

/*
void	draw_line(t_point *p1, t_point *p2, void *mlx_ptr, void *win_ptr)
{
	int dx, dy, x, y, d, s1, s2, swap=0, temp;

	dx = abs((int)p2->win_x - (int)p1->win_x);
	dy = abs((int)p2->win_y - (int)p1->win_y);
	s1 = sign((int)p2->win_x - (int)p1->win_x);
	s2 = sign((int)p2->win_y - (int)p1->win_y);

  /* Check if dx or dy has a greater range */
  /* if dy has a greater range than dx swap dx and dy
	if(dy > dx){temp = dx; dx = dy; dy = temp; swap = 1;}

  /* Set the initial decision parameter and the initial point
	d = 2 * dy - dx;
	x = (int)p1->win_x;
	y = (int)p1->win_y;

	int i;
	for(i = 1; i <= dx; i++)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF00FF);
		while(d >= 0)
    	{
      		if(swap) x = x + s1;
      		else
      		{
        		y = y + s2;
        		d = d - 2* dx;
      		}
    	}
	}
    if(swap)
		y = y + s2;
    else
		x = x + s1;
    d = d + 2 * dy;
}
*/

/*
void	draw_line(t_point *p1, t_point *p2, void *mlx_ptr, void *win_ptr)
{
	float dx;
	float dy;
	float p;
	float x;
	float y;

    dx = (p2->win_x - p1->win_x);
    dy = (p2->win_y - p1->win_y);

    x = p1->win_x;
    y = p1->win_y;

    p = ((2 * dy) - dx);

    while((x != p2->win_x) || (y != p2->win_y))
    {
        if(p >= 0)
        {
            mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF00FF);
            y = y + 1;
            p = p + (2 * (dy - dx));
        }
        else
        {
            mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF00FF);
            p = p + (2 * dy);
        }
        x = x + 1;
    }
}

*/
int main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_point p1;
	t_point	p2;

	p1 = new_point(0, 0, 0);
	p2 = new_point(300, 300, 300);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 600, 600, "line_test");
	draw_line(&p1, &p2, mlx_ptr, win_ptr);
	mlx_loop(mlx_ptr);
	return (0);
}
