#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
	std::cout << "Dog Default Constructor called" << std::endl;
}

Dog::Dog(const Dog &source): Animal(source)
{
     std::cout << "Dog Copy constructor called" << std::endl;
}

Dog &Dog::operator = (const Dog &rhs)
{
     if(this != &rhs)
        this->type = rhs.type;
    std::cout << "Dog assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" <<std::endl;
}

void Dog::makeSound(void) const {
    std::cout << "bark" << std::endl;
}