NAME = DiamondTrap
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow


SRC = main.cpp\
	ClapTrap.cpp\
	ScavTrap.cpp\
	FragTrap.cpp\
	DiamondTrap.cpp
	
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	echo "created $(NAME)"
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
		rm -f $(OBJ)
		echo "obj deleted"

fclean: clean
		rm -f $(NAME)
		echo " $(NAME) deleted"

re: fclean all

.SILENT:

.PHONY: all, clean, fclean, re
