NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c\
	  ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c\
	  ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c\
	  ft_strncmp.c ft_strnstr.c ft_itoa.c\
	  ft_strjoin.c ft_isalpha.c ft_isdigit.c ft_isascii.c\
	  ft_isalnum.c ft_isprint.c ft_tolower.c ft_toupper.c\
	  ft_atoi.c ft_calloc.c\
	  ft_strdup.c ft_substr.c ft_strtrim.c ft_split.c\
	  ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c\
	  ft_putendl_fd.c ft_putnbr_fd.c\
	  ft_strnchr.c

BON = 	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
 		ft_lstadd_back.c ft_lstdelone.c  ft_lstclear.c ft_lstiter.c\
 		ft_lstmap.c

OBJ	= $(SRC:.c=.o)

BONUS = $(BON:.c=.o)

$(NAME): $(OBJ) libft.h Makefile
		ar rc $(NAME) $(OBJ)

bonus: $(BONUS) $(NAME) libft.h Makefile
		ar rc $(NAME) *.o
.c.o:
	gcc $(FLAGS)  -c $< -o $(<:.c=.o)

all: $(NAME)

clean:
		/bin/rm -f $(OBJ) $(BONUS)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean bonus

.PHONY:	all clean fclean re bonus

