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
# define X_PIX 1000
# define Y_PIX 1000
# include <math.h>
# include <fcntl.h>
# include "./includes/libft/libft.h"
# include "mlx.h"

#include <stdio.h>

// typedef struct	s_line
// {
// 	int			x1;
// 	int			y1;
// 	int			x2;
// 	int			y2;
// }				t_line;


typedef struct s_vert
{
	int x;
	int y;
	int z;
}				t_vert;

typedef struct	s_quad
{
	t_vert		quad[4]; 
}				t_quad;

typedef struct	s_map
{
	int			x;
	int			y;
	int			**map;
}				t_map;

typedef struct	s_img
{
	char		*addr;
	int			bpp;
	int			endian;
	int			sl;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
}				t_mlx;

typedef struct	s_app
{						//buff_quad = 2;
	t_quad		*quad_buff; //buff[0] == {0,1,3,4} buff[1]
	t_vert		*vert_buff; //[0, 1, 2, 3, 4, 5] 6 verts registered
}				t_app;

void			window_init(t_mlx **st_mlx);
int				check_valid_file(const int fd, t_map **st_map);
int				**create_map(int **map, int y, int x);

void	fdf_init(t_mlx **st_mlx, t_img **st_img, t_map *st_map);
#endif
