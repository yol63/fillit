NAME = fillit

LIB_PATH = libft/

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

$(NAME): $(OBJ)
	make -C libft/ fclean && make -C libft/
	gcc $(FLAGS) -c $(SRC) -I ./ 
	gcc $(FLAGS) -o $(NAME) $(OBJ) -L $(LIB_PATH) -lft

clean:
	/bin/rm -f $(OBJ)
	make -C $(LIB_PATH) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIB_PATH) fclean

re: fclean all

.PHONY: clean fclean re make all
