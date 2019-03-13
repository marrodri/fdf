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
	t_mlx 	*mlx;
	t_map 	*map;
	t_line 	*line;
	t_img	*img;
	int 	fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if(!(check_file(fd, &(map->str_map))))
		{
			ft_putstr("Found wrong line length. Exiting.\n");
			return (0);
		}
		//window_init(&mlx->mlx_ptr, &mlx->win_ptr, &mlx->img_ptr);
		
	}
	else
	{
		ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]");
	}
	return (0);
}
