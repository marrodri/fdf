
#include "fdf_header.h"


//TODO move drawline functions here

int		mlx_pixel_image(int x, int z, char *addr, int bpp)
{
	if (x < 0 || z < 0 || x >= WIN_SZ || z >= WIN_SZ)
		return (0);
	*((int *)(addr + (x + z * WIN_SZ) * bpp)) = 0x80ff00;
	return (1);
}

void	draw_line_img(double x0, double z0, double x1, double z1, t_img *st_img)
{
	double dx;
	double dz;
	double steps;
	double x_inc;
	double z_inc;
	double x;
	double z;

	dx = x1 - x0;
	dz = z1 - z0;
	if (fabs(dx) > fabs(dz))
		steps = fabs(dx);
	else
		steps = fabs(dz);
	x_inc = dx / (float) steps;
	z_inc = dz / (float) steps;
	x = x0; 
	z = z0; 
	for (int v = 0; v < steps; v++)
	{
		x += x_inc;
		z += z_inc;
		mlx_pixel_image(x, z, st_img->addr, st_img->bpp);
	}
	return ;
}

// void draw_img(t_app *st_app, t_map *st_map)
// {

// }