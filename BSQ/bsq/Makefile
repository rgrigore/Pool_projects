NAME = bsq

SRC = *.c

FLAGS = -Wall -Werror -Wextra

all:
	@gcc -c $(FLAGS) $(SRC)
	@gcc -o $(NAME) *.o

clean:
	@/bin/rm -Rf *.o

fclean: clean
	@/bin/rm -Rf $(NAME)

re: fclean all
