
#include "fdf_header.h"

static void iso(int *x, int y, int *z)
{
	int	prev_x;
	int prev_z;

	prev_x = *x;
	prev_z = *z;
	*x = (prev_x - prev_z) *cos(0.523599);
	*z = -y + (prev_x + prev_z) * sin(0.523599);
}

t_vert *iso_view(t_map *st_map, t_vert *st_vert)
{
	int buff;
	int x;
	int z;

	buff = 0;
	while (buff < ((st_map->x) * (st_map->z)))
	{
		x = st_vert[buff].x;
		z = st_vert[buff].z;
		iso(&x, st_vert[buff].y, &z);
		st_vert[buff].z = z;
		st_vert[buff].x = x;
		buff++;
	}
	return (st_vert);
}

t_quad *parallel_view(t_quad *st_quad)
{
	//TODO calculate the coords to the parallel view
	return (st_quad);
}