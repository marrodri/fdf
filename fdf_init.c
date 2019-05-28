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

int		deal_key(int key, void *param)
{
	exit(1);
	return (0);
}

void	fdf_init(t_img **s_img, t_map *s_map, t_app *s_app)
{
	void	*p_mlx;
	void	*p_win;
	void	*p_img;
	t_img	*img;

	if ((*s_img = malloc(sizeof(t_img))) == NULL)
		return ;
	img = *s_img;
	p_mlx = mlx_init();
	p_win = mlx_new_window(p_mlx, s_app->x_sz, s_app->y_sz, "test window");
	p_img = mlx_new_image(p_mlx, WIN_SZ, WIN_SZ);
	img->addr = mlx_get_data_addr(p_img, &(img)->bpp, &(img)->sl, &(img)->endn);
	img->bpp /= 8;
	draw_img(s_app, s_map, &(img));
	mlx_put_image_to_window(p_mlx, p_win, p_img, 0, 0);
	mlx_key_hook(p_win, deal_key, (void *)0);
	mlx_loop(p_mlx);
	return ;
}
