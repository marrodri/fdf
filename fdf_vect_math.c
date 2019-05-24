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

t_quad *transl_vect(t_map *st_map, t_quad *st_quad)
{
	//TODO if vector is neg to move to screen arean
	int buff;
	int i;

	i = 0;
	buff = 0;
	while (buff < ((st_map->x - 1) * (st_map->z - 1)))
	{
		i = 0;
		while (i < 4)
		{
			st_quad[buff].quad_vert[i].x = st_quad[buff].quad_vert[i].x + 100;
			st_quad[buff].quad_vert[i].y = st_quad[buff].quad_vert[i].y + 100;
			st_quad[buff].quad_vert[i].z = st_quad[buff].quad_vert[i].z + 100;
			i++;
		}
		buff++;
	}
	return (st_quad);
}

t_quad *scale_vect(t_map *st_map, t_quad *st_quad)
{
	return NULL;
}
