/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:11:21 by marrodri          #+#    #+#             */
/*   Updated: 2019/03/08 19:06:29 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

int main(int argc, char **argv)
{
	t_app	*st_app;
	t_ptr	*st_ptr;
	t_map	*st_map;
	t_img	*st_img;
	int		fd;

	// printf("drawing a line\n");
	// window_init(&st_mlx);
 	if (argc == 2)
 	{
 		fd = open(argv[1], O_RDONLY);
 		if(!(check_valid_file(fd, &st_map, &st_app)))
 		{
			ft_putstr("Found wrong line length. Exiting.\n");
			return (0);
		}
		int y;
		int x;
		int buff = 0;

		// printf("||| or here? |||\n");
		// t_vert *test_vert = st_app->vert_buff;

		x = 0;
		y = 0;
		// printf("map is y|%d| x|%d|\n", st_map->z, st_map->x);
		// while(y < st_map->z)
		// {
		// 	x = 0;
		// 	while(x < st_map->x)
		// 	{
		// 		printf("map: y[%d],x[%d] is no.|%d|\n", y, x, st_map->map[y][x]);
		// 		x++;
		// 	}
		// 	y++;
		// }
		// while(buff <= 5)
		// {
		// 	printf("x[%d],y[%d],z[%d], vert no.|%d|\n", test_vert[buff].x, test_vert[buff].y, test_vert[buff].z, buff);
		// 	buff++;
		// }
		printf("!!!!!! QUAD_BUFFER !!!!!!\n");
		st_app->vert_buff = iso_view(st_map, st_app->vert_buff);
		st_app->vert_buff = transl_vert(st_app, st_map);
		st_app->vert_buff = scale_vect(st_app, st_map);
		st_app->quad_buff = setquad_buff(st_app->vert_buff, st_map, st_app->quad_buff);
		int i = 0;
		int size =  (st_map->x - 1) * (st_map->z - 1);
	while (i < size)
	{
		printf("quad|%d|\n", i);
		printf("vert|0| x|%f| z|%f| y|%f|\n", st_app->quad_buff[i].quad_vert[0].x, st_app->quad_buff[i].quad_vert[0].z, st_app->quad_buff[i].quad_vert[0].y);
		printf("vert|1| x|%f| z|%f| y|%f|\n", st_app->quad_buff[i].quad_vert[1].x, st_app->quad_buff[i].quad_vert[1].z, st_app->quad_buff[i].quad_vert[1].y);
		printf("vert|2| x|%f| z|%f| y|%f|\n", st_app->quad_buff[i].quad_vert[2].x, st_app->quad_buff[i].quad_vert[2].z, st_app->quad_buff[i].quad_vert[2].y);
		printf("vert|3| x|%f| z|%f| y|%f|\n", st_app->quad_buff[i].quad_vert[3].x, st_app->quad_buff[i].quad_vert[3].z, st_app->quad_buff[i].quad_vert[3].y);
		i++;
	}
		fdf_init(&st_ptr, &st_img, st_map, st_app);
	}
	else
	{
		ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]\n");
	}
	// sleep(5);
	return (0);
}