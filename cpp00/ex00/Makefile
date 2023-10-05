NAME = megaphone
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98


SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	echo "created megaphone"
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
		rm -f $(OBJ)
		echo "OBJ deleted"

fclean: clean
		rm -f $(NAME)
		echo "megaphone deleted"

re: fclean all

.SILENT:

.PHONY: all, clean, fclean, re
