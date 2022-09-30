NAME		= so_long

FLAGS		= -Wall -Wextra -Werror -I./$(HEADER)

SRC			= src/main.c src/get_next_line.c src/get_next_line_utils.c\
			src/ft_sprite.c src/ft_wasd.c src/ft_exit.c src/ft_map.c\
			src/ft_bee.c src/ft_sprite_next.c 
			
HEADER		= header/

OBJ			= $(SRC:.c=.o) 

%.o: %.c Makefile ./header/so_long.h
		gcc $(FLAGS) -Imlx  -c $<  -o $@

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJ) 
		$(MAKE) -C ./libft
		$(MAKE) -C ./ft_printf
		$(MAKE) -C ./minilibx_opengl.tgz
		gcc -g  -L./minilibx_opengl.tgz -lmlx -L./libft -lft -L./ft_printf -lftprintf -framework OpenGL -framework AppKit $^  -o $@
		
clean:
		/bin/rm -f $(OBJ) ./ft_printf/*.o ./libft/*.o ./minilibx_opengl.tgz/*.o

fclean: clean
		/bin/rm -f $(NAME) ./ft_printf/libftprintf.a ./libft/libft.a ./minilibx_opengl.tgz/libmlx.a

re: fclean all

.PHONY:	all clean fclean re bonus

.SILENT:
