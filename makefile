# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marrodri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/28 19:45:01 by marrodri          #+#    #+#              #
#    Updated: 2019/05/28 19:45:04 by marrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFLAGS = -Wall -Wextra -Werror
INC = -I ./includes/minilibx_macos
MLX = -L ./includes/minilibx_macos -lmlx -framework OpenGL -framework AppKit
LIBFT = -L ./includes/libft -lft

SRC	=	fdf_init.c fdf_main.c fdf_read_file.c \
		fdf_setbuff.c fdf_set_win.c fdf_vect_math.c \
		fdf_view.c fdf_drawline.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): 
	gcc $(CFLAGS) $(INC) $(SRC) $(MLX) $(LIBFT) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all




# cc -Wall -Wextra -Werror -I ./includes/minilibx_macos main.c -L ./includes/minilibx_macos -lmlx -framework OpenGL -framework AppKit -fsanitize=address

# cc  -I ./includes/minilibx_macos main.c fdf_*.c  -fsanitize=address

# -L ./includes/minilibx_macos -lmlx -framework OpenGL -framework AppKit -L ./includes/libft -lft



#for the includes folder gcc main.c -L libft -lft
# minilibx_macos git:(master) ✗ man man/man3/mlx_new_image.1
