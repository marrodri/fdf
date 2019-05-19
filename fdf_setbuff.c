
#include "fdf_header.h"
#include <stdio.h>

t_vert *setvert_buff(char **str_map, t_map *st_map, t_vert *st_vert)
{
	int size;
	int buff;
	int x;
	int z;
	int i;

	x = 0;
	z = 0;
	i = 0;
	buff = 0;
	size = (st_map->x) * (st_map->z);
	st_vert = malloc(size * sizeof(t_vert));
	while (str_map[z])
	{
		x = 0;
		i = 0;
		while (str_map[z][i])
		{
			if (str_map[z][i] != ' ' && str_map[z][i])
			{
				if(x == 0 || str_map[z][i - 1] == ' ')
				{
					st_vert[buff].x = (x * 100);
					st_vert[buff].y = ft_atoi(&str_map[z][i]);
					st_vert[buff].z = (z * 100);
					x++;
					buff++;
				}
			}
			i++;
		}
		z++;
	}
	printf("!!!!exiting setvert_buff!!!!\n");
	return (st_vert);
}


t_quad *setquad_buff(t_vert *st_vert, t_map *st_map, t_quad *st_quad)
{
	int buff;
	int i;
	int quad_len;
	printf("!!!!-entering setquad_buff-!!!!\n");
	buff = 0;
	quad_len = (st_map->x - 1) * (st_map->z - 1);
	st_quad = malloc(quad_len * sizeof(t_quad));
	i = 0;
	while(buff < quad_len)
	{
		st_quad[buff].quad[0] = st_vert[i];
		st_quad[buff].quad[1] = st_vert[i + 1];
		st_quad[buff].quad[2] = st_vert[i + st_map->x + 1];
		st_quad[buff].quad[3] = st_vert[i + st_map->x];
		if((i + 1) == (st_map->x - 1))
		{
			i++;
		}
		i++;
		buff++;
	}
	printf("!!!!exiting setquad_buff!!!!\n");
	return (st_quad);
}