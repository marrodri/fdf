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

t_vert *transl_vert(t_map *st_map, t_vert *st_vert)
{
	//TODO if vector is neg to move to screen arean
	int buff;
	// int i;

	// i = 0;
	buff = 0;
	while (buff < ((st_map->x) * (st_map->z)))
	{
		// i = 0;
		// while (i < 4)
		// {
			st_vert[buff].x = st_vert[buff].x + 100;
			st_vert[buff].y = st_vert[buff].y + 100;
			st_vert[buff].z = st_vert[buff].z + 100;
			// st_quad[buff].quad_vert[i].x = st_quad[buff].quad_vert[i].x + 100;
			// st_quad[buff].quad_vert[i].y = st_quad[buff].quad_vert[i].y + 100;
			// st_quad[buff].quad_vert[i].z = st_quad[buff].quad_vert[i].z + 100;
			// i++;
		// }
		buff++;
	}
	return (st_vert);
}

t_quad *scale_vect(t_map *st_map, t_quad *st_quad)
{
	return NULL;
}
