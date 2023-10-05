NAME = account
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98


SRC = tests.cpp \
	Account.cpp\
	
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	echo "created account"
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
		rm -f $(OBJ)
		echo "obj account"

fclean: clean
		rm -f $(NAME)
		echo "account deleted"

re: fclean all

.SILENT:

.PHONY: all, clean, fclean, re
