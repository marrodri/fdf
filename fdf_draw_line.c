/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 21:08:38 by marrodri          #+#    #+#             */
/*   Updated: 2019/03/09 21:08:40 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

int deal_key(int key, void *param)
{
	int x;
	int y;

	y = 500;
	x = 500;
	ft_putchar('X');
	//mlx_pixel_put(mlx_ptr, win_ptr,x +1, y +1, 0xFFFFFF);
	return 0;
}

int mlx_pixel_image(int x, int y, char *addr, int bpp)
{
	if (x < 0 || y < 0 || x >= 2000 || y >= 2000)
		return (0);
	*((int *)(addr + (x + 2000 * y) * bpp)) = 0x80ff00;
	return (1);
}

//draws line but not properly
void draw_line_top_view(double x0, double y0, double x1, double y1, char *addr, int bpp)
{
	double dx;
	double dy;
	double steps;
	double x_inc;
	double y_inc;
	double x;
	double y;

	dx = x1 - x0;
	dy = y1 - y0;
	if(fabs(dx) > fabs(dy))
	{
		steps = fabs(dx);
	}
	else
	{
		steps = fabs(dy);
	}
	x_inc = dx / (float) steps;
	y_inc = dy / (float) steps;
	x = x0;
	y = y0;
	for(int v = 0; v < steps; v++)
	{
		x += x_inc;
		y += y_inc;
		mlx_pixel_image(x, y, addr, bpp);
	}
	return ;
}

void window_init(void *mlx_ptr, void *win_ptr, void *img_ptr)
{
	char *addr;
	int bpp;
	int sl;
	int endian;
	int x;
	int y;

	x = 250;
	y = 250;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 2000, 2000, "mlx 42");
	img_ptr = mlx_new_image(mlx_ptr, 2000, 2000);
	addr = mlx_get_data_addr(img_ptr, &bpp, &sl, &endian);
	bpp /= 8;
	draw_line_top_view(100, 900, 900, 100, addr, bpp);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
    return ;
}

