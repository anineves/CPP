NAME = account
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98


SRC = tests.cpp \
	Account.cpp\
	
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	echo "created $(NAME)"
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
		rm -f $(OBJ)
		echo "obj deleted"

fclean: clean
		rm -f $(NAME)
		echo " $(NAME) deleted"

re: fclean all

.SILENT:

.PHONY: all, clean, fclean, re