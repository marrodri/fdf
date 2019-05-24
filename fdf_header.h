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
# define COLOR 0xFFFFFF
# define WIN_SZ 1000
# include <math.h>
# include <fcntl.h>
# include "./includes/libft/libft.h"
# include "mlx.h"

#include <stdio.h>

typedef struct	s_win
{
	int			x_win_sz;
	int			y_win_sz;
}				t_win;

typedef struct	s_vec_math
{
	double 		neg_x;
	double		neg_z;
	double		scale_x;
	double		scale_y;
}				t_vec_math;

typedef struct	s_vert
{
	double		x;
	double		y;
	double		z;
}				t_vert;

typedef struct	s_quad
{
	t_vert		quad_vert[4]; 
}				t_quad;

typedef struct	s_map
{
	int			x;
	int			z;
}				t_map;

typedef struct	s_img
{
	char		*addr;
	int			bpp;
	int			endian;
	int			sl;
}				t_img;

typedef struct	s_ptr
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
}				t_ptr;

typedef struct	s_app
{
	t_quad		*quad_buff;
	t_vert		*vert_buff;
}				t_app;

void			window_init(t_ptr **st_ptr);
int				check_valid_file(const int fd, t_map **st_map, t_app **st_app);
int				**create_map(int **map, int y, int x);
t_quad			*iso_view(t_map *st_map ,t_quad *st_quad);
t_quad			*transl_vect(t_map *st_map, t_quad *st_quad);

t_vert			*setvert_buff(char **str_map, t_map *st_map, t_vert *st_vert);
t_quad			*setquad_buff(t_vert *st_vert, t_map *st_map, t_quad *st_quad);

void			fdf_init(t_ptr **st_ptr, t_img **st_img, t_map *st_map, t_app *st_app);
#endif
