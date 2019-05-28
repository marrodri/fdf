/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vect_math.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 15:50:39 by marrodri          #+#    #+#             */
/*   Updated: 2019/05/24 15:50:41 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

t_vert	*scale_xy(t_app *st_app, t_map *st_map, double out_x, double out_z)
{
	int	buff;

	if (out_x > 0)
	{
		buff = 0;
		out_x = st_app->x_win_sz / out_x;
		while (buff < ((st_map->x) * (st_map->z)))
		{
			st_app->vert_buff[buff].x = st_app->vert_buff[buff].x * out_x;
			buff++;
		}
	}
	if (out_z > 0)
	{
		buff = 0;
		out_z = st_app->y_win_sz / out_z;
		while (buff < ((st_map->x) * (st_map->z)))
		{
			st_app->vert_buff[buff].z = st_app->vert_buff[buff].z * out_z;
			buff++;
		}
	}
	return (st_app->vert_buff);
}

t_vert	*transl_vert(t_app *st_app, t_map *st_map)
{
	int		buff;
	double	dif_x;
	double	dif_z;

	buff = 0;
	dif_x = 0;
	dif_z = 0;
	while (buff < ((st_map->x) * (st_map->z)))
	{
		if (st_app->vert_buff[buff].x < dif_x)
			dif_x = st_app->vert_buff[buff].x;
		if (st_app->vert_buff[buff].z < dif_z)
			dif_z = st_app->vert_buff[buff].z;
		buff++;
	}
	buff = 0;
	dif_x = fabs(dif_x) + 5;
	dif_z = fabs(dif_z) + 5;
	while (buff < ((st_map->x) * (st_map->z)))
	{
		st_app->vert_buff[buff].z = st_app->vert_buff[buff].z + dif_z;
		st_app->vert_buff[buff].x = st_app->vert_buff[buff].x + dif_x;
		buff++;
	}
	return (st_app->vert_buff);
}

t_vert	*scale_vect(t_app *st_app, t_map *st_map)
{
	int		buff;
	double	out_x;
	double	out_z;

	buff = 0;
	out_x = 0;
	out_z = 0;
	while (buff < ((st_map->x) * (st_map->z)))
	{
		if (st_app->vert_buff[buff].x > st_app->x_win_sz)
		{
			if (out_x < st_app->vert_buff[buff].x)
				out_x = st_app->vert_buff[buff].x;
		}
		if (st_app->vert_buff[buff].z > st_app->y_win_sz)
		{
			if (out_z < st_app->vert_buff[buff].z)
				out_z = st_app->vert_buff[buff].z;
		}
		buff++;
	}
	st_app->vert_buff = scale_xy(st_app, st_map, out_x, out_z);
	return (st_app->vert_buff);
}
