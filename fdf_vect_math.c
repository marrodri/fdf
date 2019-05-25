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

t_vert *transl_vert(t_app *st_app, t_map *st_map)
{
	//TODO if vector is neg to move to screen arean
	int buff;
	double dif_x;
	double dif_z;

	buff = 0;
	dif_x = 0;
	dif_z = 0;
	while (buff < ((st_map->x) * (st_map->z)))
	{
		if(st_app->vert_buff[buff].x < dif_x)
		{
			dif_x = st_app->vert_buff[buff].x;
		}
		if((st_app->vert_buff[buff].z < dif_z))
		{
			dif_z = st_app->vert_buff[buff].z;
		}
			// st_app->vert_buff[buff].x = st_app->vert_buff[buff].x + 300;
			// st_app->vert_buff[buff].y = st_app->vert_buff[buff].y + 300;
			// st_app->vert_buff[buff].z = st_app->vert_buff[buff].z + 300;
		buff++;
	}
	buff = 0;
	dif_x = fabs(dif_x) + 5;
	dif_z = fabs(dif_z) + 5;
	while(buff < ((st_map->x) * (st_map->z)))
	{
		st_app->vert_buff[buff].z = st_app->vert_buff[buff].z + dif_z;
		st_app->vert_buff[buff].x = st_app->vert_buff[buff].x + dif_x;
		buff++;
	}
	return (st_app->vert_buff);
}

t_quad *scale_vect(t_map *st_map, t_quad *st_quad)
{
	return NULL;
}
