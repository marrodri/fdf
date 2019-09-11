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

int		close_win_x(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int		deal_key(int key, void *param)
{
<<<<<<< HEAD
	(void)param;
	if (key == 53)
		exit(1);
=======
	if (key == 27)
		(void)param;
	exit(1);
>>>>>>> b94bef061e98bbfc64216e82a0844bac550a0d3a
	return (0);
}

void	fdf_init(t_img *st_img, t_map *st_map, t_app *st_app)
{
	void	*p_mlx;
	void	*p_win;
	void	*p_img;

	p_mlx = mlx_init();
	p_win = mlx_new_window(p_mlx, st_app->x_sz, st_app->y_sz, "test window");
	p_img = mlx_new_image(p_mlx, WIN_SZ, WIN_SZ);
	st_img->addr = mlx_get_data_addr(p_img, &st_img->bpp,
								&st_img->sl, &st_img->endn);
	st_img->bpp /= 8;
	draw_img(st_app, st_map, &st_img);
	mlx_put_image_to_window(p_mlx, p_win, p_img, 0, 0);
<<<<<<< HEAD
	mlx_key_hook(p_win, deal_key, (void *)0);
=======
	mlx_hook(p_win, 2, 27, deal_key, (void *)0);
>>>>>>> b94bef061e98bbfc64216e82a0844bac550a0d3a
	mlx_hook(p_win, 17, (1L << 17), close_win_x, (void*)0);
	mlx_loop(p_mlx);
	return ;
}
