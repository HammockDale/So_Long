NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC =	ft_strlen.c ft_memset.c ft_bzero.c ft_isdigit.c ft_calloc.c	ft_strdup.c\
		ft_printf.c ft_c.c ft_s.c ft_s_null.c ft_i.c ft_itoa.c ft_u.c ft_utoa.c\
		ft_x.c ft_xtoa.c ft_xb.c ft_xbtoa.c ft_p.c ft_p_null.c ft_ptoa.c ft_printchr.c\
		ft_printf_utils.c

OBJ	= $(SRC:.c=.o)


$(NAME): $(OBJ) ft_printf.h Makefile
		ar rc $(NAME) $(OBJ) 

.c.o:
	gcc $(FLAGS)  -c $< -o $(<:.c=.o)

all: $(NAME) 

clean:
		/bin/rm -f $(OBJ) $(BONUS)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean

.PHONY:	all clean fclean re

