NAME = zombie
CCXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98


SRC = main.cpp \
	Zombie.cpp\
	newZombie.cpp\
	randomChump.cpp
	
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	echo "created zombie"
	$(CCXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
		rm -f $(OBJ)
		echo "obj deleted"

fclean: clean
		rm -f $(NAME)
		echo " zombie deleted"

re: fclean all

.SILENT:

.PHONY: all, clean, fclean, re
