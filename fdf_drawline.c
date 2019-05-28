/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_drawline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 17:34:23 by marrodri          #+#    #+#             */
/*   Updated: 2019/05/27 17:34:26 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

int		mlx_pixel_image(int x, int z, char *addr, int bpp)
{
	if (x < 0 || z < 0 || x >= WIN_SZ || z >= WIN_SZ)
		return (0);
	*((int *)(addr + (x + z * WIN_SZ) * bpp)) = 0x80ff00;
	return (1);
}

void	draw_line_img(double x0, double z0, double x1, double z1, t_vect *st_vect, t_img *st_img)
{
	double	steps;
	double	x_inc;
	double	z_inc;

	st_vect->dx = x1 - x0;
	st_vect->dz = z1 - z0;
	if (fabs(st_vect->dx) > fabs(st_vect->dz))
		steps = fabs(st_vect->dx);
	else
		steps = fabs(st_vect->dz);
	x_inc = st_vect->dx / (float) steps;
	z_inc = st_vect->dz / (float) steps;
	st_vect->x = x0; 
	st_vect->z = z0; 
	for (int v = 0; v < steps; v++)
	{
		st_vect->x += x_inc;
		st_vect->z += z_inc;
		mlx_pixel_image(st_vect->x, st_vect->z, st_img->addr, st_img->bpp);
	}
	return ;
}

void	draw_img(t_app *st_app, t_map *st_map, t_img **st_img)
{
	int		buff;
	t_vert	*verts;
	t_vect	*st_vect;

	st_vect = malloc(sizeof(t_vect));
	buff = 0;
	while (buff < ((st_map->x - 1) * (st_map->z - 1)))
	{
		verts = st_app->quad_buff[buff].quad_vert;
		draw_line_img(verts[0].x, verts[0].z, verts[1].x, verts[1].z, st_vect, *st_img);
		draw_line_img(verts[2].x, verts[2].z, verts[3].x, verts[3].z, st_vect, *st_img);
		draw_line_img(verts[0].x, verts[0].z, verts[2].x, verts[2].z, st_vect, *st_img);
		draw_line_img(verts[1].x, verts[1].z, verts[3].x, verts[3].z, st_vect, *st_img);
		buff++;
	}
	return ;
}
