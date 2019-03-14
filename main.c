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
	t_mlx 	*st_mlx;
	t_map 	*st_map;
	t_line 	*st_line;
	t_img	*st_img;
	int 	fd;




 	if (argc == 2)
 	{
 		fd = open(argv[1], O_RDONLY);
 		if(!(check_valid_file(fd, st_map)))
 		{
			ft_putstr("Found wrong line length. Exiting.\n");
			return (0);
		}



	}
	else
	{
		ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]");
	}
	return (0);
}

		// char **test;
		// char m[100] = "00 01 02,00xf123fd 03 04  05 \n 10 11 12 13 14 15\n 20 21 22 23 24 25";
		// test = ft_strsplit(m,'\n');
		// st_map->map = create_map(test);
		// //window_init(&mlx->mlx_ptr, &mlx->win_ptr, &mlx->img_ptr);
		// int x = 0;
		// int y = 0;
		// while (st_map->map[y] != NULL)
		// {
		// 	printf("LOOP: y is %d\n", y);
		// 	x = 0;
		// 	while (st_map->map[y][x])
		// 	{
		// 		printf("map [%d][%d] |%s|\n", y, x, st_map->map[y][x]);
		// 		x++;
		// 	}
		// 	y++;
		// }