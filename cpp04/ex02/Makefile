NAME = Animal
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98


SRC = main.cpp\
	Animal.cpp\
	Dog.cpp\
	Cat.cpp\
	WrongAnimal.cpp\
	WrongCat.cpp\
	Brain.cpp
	
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


.PHONY: all, clean, fclean, re
