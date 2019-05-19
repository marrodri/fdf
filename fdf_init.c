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

void	draw_wireframe_image(t_quad *st_quad, char *addr, int bpp, int i, int buff)
{
	double dx;
	double dz;
	double steps;
	double x_inc;
	double z_inc;
	double x;
	double z;

	dx = st_quad[buff].quad[i + 1].x - st_quad[buff].quad[i].x;
	dz = st_quad[buff].quad[i + 1].z - st_quad[buff].quad[i].z;
	if (fabs(dx) > fabs(dz))
		steps = fabs(dx);
	else
		steps = fabs(dz);

	x_inc = dx / (double) steps;
	z_inc = dz / (double) steps;
	x = st_quad[0].quad[0].x;
	z = st_quad[0].quad[0].z;
	for (int v = 0; v < steps; v++)
	{
		x += x_inc;
		z += z_inc;
		mlx_pixel_image(x, z, addr, bpp);
	}

	return ;
}

void	fdf_init(t_ptr **st_ptr, t_img **st_img, t_map *st_map, t_app *st_app)
{
	int i;
	int buff;

	buff = 0;
	i = 0;

	if ((*st_ptr = malloc(sizeof(t_ptr))) == NULL)
		return ;
	if ((*st_img = malloc(sizeof(t_img))) == NULL)
		return ;

	(*st_ptr)->mlx_ptr = mlx_init();
	(*st_ptr)->win_ptr = mlx_new_window((*st_ptr)->mlx_ptr, WIN_SZ, WIN_SZ, "test window");
	(*st_ptr)->img_ptr = mlx_new_image((*st_ptr)->mlx_ptr, WIN_SZ, WIN_SZ);
	(*st_img)->addr = mlx_get_data_addr((*st_ptr)->img_ptr, &(*st_img)->bpp, &(*st_img)->sl, &(*st_img)->endian);
	(*st_img)->bpp /= 8;
	while (buff < 4)
	{
		i = 0;
		while(i < 4)
		{
			draw_wireframe_image(st_app->quad_buff, (*st_img)->addr, (*st_img)->bpp, i, buff);
			i++;
		}
		buff++;
	}
	mlx_put_image_to_window((*st_ptr)->mlx_ptr, (*st_ptr)->win_ptr, (*st_ptr)->img_ptr, 0, 0);
	mlx_loop((*st_ptr)->mlx_ptr);
}
