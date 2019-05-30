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
# include "libft/libft.h"
# include "mlx.h"

typedef struct	s_vect
{
	double dx;
	double dz;
	double x;
	double z;
}				t_vect;

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
	int			endn;
	int			sl;
}				t_img;

typedef struct	s_app
{
	t_quad		*quad_buff;
	t_vert		*vert_buff;
	int			x_sz;
	int			y_sz;
}				t_app;

void			set_win_sz(t_app **st_app, t_map *st_map);
int				check_valid_file(const int fd, t_map **st_map, t_app **st_app);
int				**create_map(int **map, int y, int x);
t_vert			*transf_view(t_map *st_map, t_vert *st_vert, char vw);
t_vert			*transl_vert(t_app *st_app, t_map *st_map);
void			vert_buff_malloc(char **str_map, t_map *st_map, t_vert **st_vert);
t_vert			*scale_vect(t_app *st_app, t_map *st_map);
t_quad			*quad_buff_malloc(t_vert *st_vert, t_map *st_map, t_quad *st_quad);
void			fdf_init(t_img *st_img, t_map *st_map, t_app *st_app);
void			draw_img(t_app *st_app, t_map *st_map, t_img **st_img);
void			free_app(t_app *st_app);
#endif
