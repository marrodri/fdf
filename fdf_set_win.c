
#include "fdf_header.h"

void set_win_sz(t_app **st_app, t_map *st_map)
{
	int buff;

	buff = 0;
	(*st_app)->x_win_sz = 0;
	(*st_app)->y_win_sz = 0;
	while (buff < ((st_map->x) * (st_map->z)))
	{
		if ((*st_app)->vert_buff[buff].x > (*st_app)->x_win_sz)
		{
			(*st_app)->x_win_sz = (*st_app)->vert_buff[buff].x + 10;
		}
		if ((*st_app)->vert_buff[buff].z > (*st_app)->y_win_sz)
		{
			(*st_app)->y_win_sz = (*st_app)->vert_buff[buff].z + 10;
		}
		buff++;
	}
	if ((*st_app)->x_win_sz > WIN_SZ)
		(*st_app)->x_win_sz = WIN_SZ;
	if ((*st_app)->y_win_sz > WIN_SZ)
		(*st_app)->y_win_sz = WIN_SZ;
}