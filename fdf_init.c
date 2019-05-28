/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:05:13 by marrodri          #+#    #+#             */
/*   Updated: 2019/05/27 18:05:16 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

int deal_key(int key, void *param)
{
	exit(1);
	return (0);
}

void	fdf_init(t_ptr **st_ptr, t_img **st_img, t_map *st_map, t_app *st_app)
{
	void *mlx;
	void *win;
	void *img;

	if ((*st_ptr = malloc(sizeof(t_ptr))) == NULL)
		return ;
	if ((*st_img = malloc(sizeof(t_img))) == NULL)
		return ;
	mlx = mlx_init();
	win = mlx_new_window(mlx, st_app->x_win_sz, st_app->y_win_sz, "test window");
	img = mlx_new_image(mlx, WIN_SZ, WIN_SZ);
	(*st_img)->addr = mlx_get_data_addr(img, &(*st_img)->bpp, &(*st_img)->sl, &(*st_img)->endian);
	(*st_img)->bpp /= 8;
	draw_img(st_app, st_map, &(*st_img));
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_key_hook(win, deal_key, (void *)0);
	mlx_loop(mlx);
	return ;
}
