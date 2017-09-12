/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:05:21 by rvinnako          #+#    #+#             */
/*   Updated: 2017/09/11 16:55:00 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//#include <graphics.h>

void	draw_line(t_point *p1, t_point *p2, void *mlx_ptr, void *win_ptr)
{
	float dx;
	float dy;
	float p;
	float x;
	float y;

    dx=p2->win_x - p1->win_x;
    dy=p2->win_y - p1->win_y;

    x=p1->win_x;
    y=p1->win_y;

    p=2*dy-dx;

    while(x < p2->win_x)
    {
        if(p>=0)
        {
            mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF00FF);
            y=y+1;
            p=p+2*dy-2*dx;
        }
        else
        {
            mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFF00FF);
            p=p+2*dy;
        }
        x=x+1;
    }
}

/*
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


    int gdriver=DETECT, gmode, error, x0, y0, x1, y1;
    initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");

    printf("Enter co-ordinates of first point: ");
    scanf("%d%d", &x0, &y0);

    printf("Enter co-ordinates of second point: ");
    scanf("%d%d", &x1, &y1);
    drawline(x0, y0, x1, y1);

    return 0;
}
	*/
