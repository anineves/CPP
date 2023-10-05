NAME = phonebook
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic


SRC = main.cpp \
	PhoneBook.cpp\
	Contact.cpp
	
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	echo "created phonebook"
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
		rm -f $(OBJ)
		echo "obj deleted"

fclean: clean
		rm -f $(NAME)
		echo "phonebook deleted"

re: fclean all

.SILENT:

.PHONY: all, clean, fclean, re
