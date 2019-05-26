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

int		mlx_pixel_image(int x, int z, char *addr, int bpp)
{
	if (x < 0 || z < 0 || x >= WIN_SZ || z >= WIN_SZ)
		return (0);
	*((int *)(addr + (x + z * WIN_SZ) * bpp)) = 0x80ff00;
	return (1);
}

void	draw_wireframe_image(double x0, double x1, double z0, double z1, t_img *st_img)
{
	double dx;
	double dz;
	double steps;
	double x_inc;
	double z_inc;
	double x;
	double z;
	
	dx = x1 - x0; //vx1 - vx0;
	dz = z1 - z0; //vz1 - vz0;
	if (fabs(dx) > fabs(dz))
		steps = fabs(dx);
	else
		steps = fabs(dz);
	x_inc = dx / (float) steps;
	z_inc = dz / (float) steps;
	x = x0; //vx0;
	z = z0; //vy0;
	for (int v = 0; v < steps; v++)
	{
		x += x_inc;
		z += z_inc;
		mlx_pixel_image(x, z, st_img->addr, st_img->bpp);
	}
	return ;
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
			draw_wireframe_image(verts[0].x, verts[1].x, verts[0].z, verts[1].z, *st_img);
			draw_wireframe_image(verts[2].x, verts[3].x, verts[2].z, verts[3].z, *st_img);
			draw_wireframe_image(verts[0].x, verts[2].x, verts[0].z, verts[2].z, *st_img);
			draw_wireframe_image(verts[1].x, verts[3].x, verts[1].z, verts[3].z, *st_img);
		buff++;
	}
	mlx_put_image_to_window((*st_ptr)->mlx_ptr, (*st_ptr)->win_ptr, (*st_ptr)->img_ptr, 0, 0);
	mlx_loop((*st_ptr)->mlx_ptr);
}
