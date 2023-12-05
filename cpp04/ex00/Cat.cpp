#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
	std::cout << "Cat Default Constructor called" << std::endl;
}


Cat::Cat(const Cat &source): Animal(source)
{
     std::cout << "Cat Copy constructor called" << std::endl;
}

Cat &Cat::operator = (const Cat &rhs)
{
     if(this != &rhs)
        this->type = rhs.type;
    std::cout << "Cat assignment operator called" << std::endl;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" <<std::endl;
}

void Cat::makeSound(void) const {
    std::cout << "miau" << std::endl;
}