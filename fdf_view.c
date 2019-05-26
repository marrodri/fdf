
#include "fdf_header.h"

static void calc_view(int *x, int y, int *z, float ang)
{
	int	prev_x;
	int prev_z;

	prev_x = *x;
	prev_z = *z;
	*x = (prev_x - prev_z) *cos(ang);
	*z = -y + (prev_x + prev_z) * sin(ang);
}

t_vert *transf_view(t_map *st_map, t_vert *st_vert, char vw)
{
	int buff;
	int x;
	int z;
	float ang;

	buff = 0;
	if(vw == 'i')
		ang = 0.523599;
	else if (vw == 'p')
		ang = 1.134459;
	while (buff < ((st_map->x) * (st_map->z)))
	{
		x = st_vert[buff].x;
		z = st_vert[buff].z;
		calc_view(&x, st_vert[buff].y, &z, ang);
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