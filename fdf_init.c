/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_set_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:40:16 by marrodri          #+#    #+#             */
/*   Updated: 2019/03/18 11:40:18 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

// int win_scale(int size)
// {
// 	size = 0;
// 	return (size);
// }

void set_img()
{

}

void fdf_init(t_mlx **st_mlx, t_img **st_img, t_map *st_map)
{
	if ((*st_mlx = malloc(sizeof(t_mlx))) == NULL)
		return ;

	if ((*st_img = malloc(sizeof(t_img))) == NULL)
		return ;

	(*st_mlx)->mlx_ptr = mlx_init();
	(*st_mlx)->win_ptr = mlx_new_window((*st_mlx)->mlx_ptr, (st_map->x) * 200, (st_map->y) * 200, "test window");
	(*st_mlx)->img_ptr = mlx_new_image((*st_mlx)->mlx_ptr, (st_map->x) * 200, (st_map->y) * 200);
	()->
	mlx_loop((*st_mlx)->mlx_ptr);
}
