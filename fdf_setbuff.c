/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_setbuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 11:39:10 by marrodri          #+#    #+#             */
/*   Updated: 2019/05/19 11:39:13 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

t_vert	*assign_buff(t_vert *st_vert, char **str_map)
{
	int buff;
	int x;
	int z;
	int i;

	buff = 0;
	z = -1;
	while (str_map[++z])
	{
		x = 0;
		i = -1;
		while (str_map[z][++i])
			if (str_map[z][i] != ' ' && str_map[z][i] &&
				(x == 0 || str_map[z][i - 1] == ' '))
			{
				st_vert[buff].x = (x++ * 25);
				st_vert[buff].y = 25 * ft_atoi(&str_map[z][i]);
				st_vert[buff++].z = (z * 25);
			}
	}
	return (st_vert);
}

void	vert_buff_malloc(char **str_map, t_map *st_map, t_vert **st_vert)
{
	int size;

	size = (st_map->x) * (st_map->z);
	*st_vert = malloc(size * sizeof(t_vert));
	*st_vert = assign_buff(*st_vert, str_map);
}

t_quad	*quad_buff_malloc(t_vert *st_vert, t_map *st_map, t_quad *st_quad)
{
	int buff;
	int i;
	int vert_len;
	int quad_len;

	buff = 0;
	vert_len = st_map->x;
	quad_len = (st_map->x - 1) * (st_map->z - 1);
	st_quad = malloc(quad_len * sizeof(t_quad));
	i = 0;
	while (buff < quad_len)
	{
		st_quad[buff].quad_vert[0] = st_vert[i];
		st_quad[buff].quad_vert[1] = st_vert[i + 1];
		st_quad[buff].quad_vert[2] = st_vert[i + st_map->x];
		st_quad[buff].quad_vert[3] = st_vert[i + st_map->x + 1];
		if ((i + 1) == (vert_len - 1))
		{
			vert_len = st_map->x + vert_len;
			i++;
		}
		i++;
		buff++;
	}
	return (st_quad);
}
