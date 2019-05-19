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

// int win_scale(int size)
// {
// 	size = 0;
// 	return (size);
// }

int		mlx_pixel_image(int x, int y, char *addr, int bpp)
{
	if (x < 0 || y < 0 || x >= WIN_SZ || y >= WIN_SZ)
		return (0);
	*((int *)(addr + (x + WIN_SZ * y) * bpp)) = 0x80ff00;
	return (1);
}

void	draw_wireframe_image(t_quad *st_quad, char *addr, int bpp)
{
	
	return ;
}

void	fdf_init(t_ptr **st_ptr, t_img **st_img, t_map *st_map, t_app *st_app)
{
	if ((*st_ptr = malloc(sizeof(t_ptr))) == NULL)
		return ;
	if ((*st_img = malloc(sizeof(t_img))) == NULL)
		return ;

	(*st_ptr)->mlx_ptr = mlx_init();
	(*st_ptr)->win_ptr = mlx_new_window((*st_ptr)->mlx_ptr, WIN_SZ, WIN_SZ, "test window");
	(*st_ptr)->img_ptr = mlx_new_image((*st_ptr)->mlx_ptr, WIN_SZ, WIN_SZ);
	(*st_img)->addr = mlx_get_data_addr((*st_ptr)->img_ptr, &(*st_img)->bpp, &(*st_img)->sl, &(*st_img)->endian);
	(*st_img)->bpp /= 8;

	draw_wireframe_image(st_app->quad_buff, (*st_img)->addr, (*st_img)->bpp);
	mlx_loop((*st_ptr)->mlx_ptr);
}
