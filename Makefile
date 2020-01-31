NAME = fillit

LIB_PATH = ./libft

LIBFT = ./libft/libft.a

HEAD = ./

SRC =	get_next_line.c \
	list.c \
	coord.c \
	main.c \
	validation.c \
	put.c \
	w_h_counter.c
	
HEAD_FILES =	get_next_line.h \
		validation.h \
		fillit.h 

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) -I $(LIB_PATH)

$(LIBFT):
	make -C libft/

clean:
	/bin/rm -f $(OBJ)
	make -C $(LIB_PATH) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIB_PATH) fclean

re: fclean all

.PHONY: clean fclean re make all
