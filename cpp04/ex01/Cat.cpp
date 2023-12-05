#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

Cat::Cat()
{
    this->type = "Cat";
    this->brain = new Brain();
	std::cout << "Cat Default Constructor called" << std::endl;
}


Cat::Cat(const Cat &source): Animal()
{
    *this = source;
    std::cout << "Cat Copy constructor called" << std::endl;
}

Cat &Cat::operator = (const Cat &rhs)
{
    if(this != &rhs)
    {
        this->type = rhs.type;
        this->brain = new Brain(*(rhs.brain));
    }
    std::cout << "Cat assignment operator called" << std::endl;
    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat Destructor called" <<std::endl;
}

void Cat::makeSound(void) const {
    std::cout << "miau" << std::endl;
}

Brain *Cat::getBrain(void) const
{
	return (this->brain);
}