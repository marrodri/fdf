/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 21:08:59 by marrodri          #+#    #+#             */
/*   Updated: 2019/03/12 19:05:51 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_HEADER_H
# define FDF_HEADER_H
# include <math.h>
# include <fcntl.h>
# include "./includes/libft/libft.h"
# include "mlx.h"

#include <stdio.h>

typedef struct	s_line
{
	int			*x1;
	int			*y1;
	int			*x2;
	int			*y2;
}				t_line;

typedef struct	s_map
{
	char 		***map;
	int			x;
	int			y;
	int			z;
}				t_map;

typedef struct	s_img
{
	char		*addr;
	int			bpp;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
}				t_mlx;

void			window_init(void *mlx_ptr, void *win_ptr, void *img_ptr);
int				check_valid_file(const int fd, t_map *map);
char			***create_map(char **str_spltd);
#endif
