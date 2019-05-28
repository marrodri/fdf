/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_set_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:40:16 by marrodri          #+#    #+#             */
/*   Updated: 2019/03/18 11:40:18 by marrodri         ###   ########.fr       */
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
	int i;
	int buff;
	t_vert *verts;

	buff = 0;
	i = 0;

	if ((*st_ptr = malloc(sizeof(t_ptr))) == NULL)
		return ;
	if ((*st_img = malloc(sizeof(t_img))) == NULL)
		return ;

	(*st_ptr)->mlx_ptr = mlx_init();
	(*st_ptr)->win_ptr = mlx_new_window((*st_ptr)->mlx_ptr, st_app->x_win_sz, st_app->y_win_sz, "test window");
	(*st_ptr)->img_ptr = mlx_new_image((*st_ptr)->mlx_ptr, WIN_SZ, WIN_SZ);
	(*st_img)->addr = mlx_get_data_addr((*st_ptr)->img_ptr, &(*st_img)->bpp, &(*st_img)->sl, &(*st_img)->endian);
	(*st_img)->bpp /= 8;
	while (buff < ((st_map->x - 1) * (st_map->z - 1)))
	{
		verts = st_app->quad_buff[buff].quad_vert;
			draw_line_img(verts[0].x, verts[0].z, verts[1].x, verts[1].z, *st_img);
			draw_line_img(verts[2].x, verts[2].z, verts[3].x, verts[3].z, *st_img);
			draw_line_img(verts[0].x, verts[0].z, verts[2].x, verts[2].z, *st_img);
			draw_line_img(verts[1].x, verts[1].z, verts[3].x, verts[3].z, *st_img);
		buff++;
	}
	mlx_put_image_to_window((*st_ptr)->mlx_ptr, (*st_ptr)->win_ptr, (*st_ptr)->img_ptr, 0, 0);
	mlx_key_hook((*st_ptr)->win_ptr, deal_key, (void *)0);
	mlx_loop((*st_ptr)->mlx_ptr);
	return ;
}
