
#include "fdf_header.h"

static void iso(int *x, int y, int *z)
{
	int prev_x;
	int prev_z;

	prev_x = *x;
	prev_z = *z;
	*x = (prev_x - prev_z) *cos(0.523599);
	*z = -y + (prev_x + prev_z) * sin(0.523599);
}

t_quad *iso_view(t_map *st_map ,t_quad *st_quad)
{
	int buff;
	int i;
	int x;
	int z;

	i = 0;
	buff = 0;

	while (buff < ((st_map->x - 1) * (st_map->z - 1)))
	{
		i = 0;
		while(i < 4)
		{
			x = (st_quad[buff].quad_vert[i].x);
			z = (st_quad[buff].quad_vert[i].z);
			iso(&x, st_quad[buff].quad_vert[i].y, &z);
			(st_quad[buff].quad_vert[i].z) = z;
			(st_quad[buff].quad_vert[i].x) = x;
			i++;
		}
		buff++;
	}
	return (st_quad);
}

t_quad *parallel_view(t_quad *st_quad)
{
	//TODO calculate the coords to the parallel view
	return st_quad;
}