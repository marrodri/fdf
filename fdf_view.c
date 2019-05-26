
#include "fdf_header.h"

static void trans_view(int *x, int y, int *z, float vw)
{
	int	prev_x;
	int prev_z;

	prev_x = *x;
	prev_z = *z;
	*x = (prev_x - prev_z) *cos(vw);
	*z = -y + (prev_x + prev_z) * sin(vw);
}

t_vert *iso_view(t_map *st_map, t_vert *st_vert)
{
	int buff;
	int x;
	int z;
	const float iso = 0.523599;
	const float par = 0.707106;
	buff = 0;
	while (buff < ((st_map->x) * (st_map->z)))
	{
		x = st_vert[buff].x;
		z = st_vert[buff].z;
		trans_view(&x, st_vert[buff].y, &z, par);
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