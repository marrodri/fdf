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

 	if (argc == 3)
 	{
 		fd = open(argv[1], O_RDONLY);
 		if(!(check_valid_file(fd, &st_map, &st_app)))
 		{
			ft_putstr("Found wrong line length. Exiting.\n");
			return (0);
		}
		st_app->vert_buff = transf_view(st_map, st_app->vert_buff, argv[2][0]);
		st_app->vert_buff = transl_vert(st_app, st_map);
		set_win_sz(&st_app, st_map);
		st_app->vert_buff = scale_vect(st_app, st_map);
		st_app->quad_buff = setquad_buff(st_app->vert_buff, st_map, st_app->quad_buff);
		fdf_init(&st_ptr, &st_img, st_map, st_app);
	}
	else
	{
		ft_putstr("Usage : ./fdf <filename> 'view projection' [i = isometric, p = parallel]\n");
	}
	return (0);
}