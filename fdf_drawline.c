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

void	draw_line_img(t_vert v0, t_vert v1, t_vect *st_vect, t_img *st_img)
{
	double	steps;
	double	x_inc;
	double	z_inc;
	int		i;

	i = 0;
	st_vect->dx = v1.x - v0.x;
	st_vect->dz = v1.z - v0.z;
	if (fabs(st_vect->dx) > fabs(st_vect->dz))
		steps = fabs(st_vect->dx);
	else
		steps = fabs(st_vect->dz);
	x_inc = st_vect->dx / (float)steps;
	z_inc = st_vect->dz / (float)steps;
	st_vect->x = v0.x;
	st_vect->z = v0.z;
	while (i < steps)
	{
		st_vect->x += x_inc;
		st_vect->z += z_inc;
		mlx_pixel_image(st_vect->x, st_vect->z, st_img->addr, st_img->bpp);
		i++;
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
		draw_line_img(verts[0], verts[1], st_vect, *st_img);
		draw_line_img(verts[2], verts[3], st_vect, *st_img);
		draw_line_img(verts[0], verts[2], st_vect, *st_img);
		draw_line_img(verts[1], verts[3], st_vect, *st_img);
		buff++;
	}
	free(st_vect);
	return ;
}
