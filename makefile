cc  -I ./includes/minilibx_macos main.c -L ./includes/minilibx_macos -lmlx -framework OpenGL -framework AppKit

cc  -I ./includes/minilibx_macos main.c fdf_*.c  


-L ./includes/minilibx_macos -lmlx -framework OpenGL -framework AppKit -L ./includes/libft -lft



#for the includes folder gcc main.c -L libft -lft
# minilibx_macos git:(master) ✗ man man/man3/mlx_new_image.1