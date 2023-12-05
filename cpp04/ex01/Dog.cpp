#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
    this->brain = new Brain();
	std::cout << "Dog Default Constructor called" << std::endl;
}

Dog::Dog(const Dog &source): Animal()
{
     *this = source;
     std::cout << "Dog Copy constructor called" << std::endl;
}

Dog &Dog::operator = (const Dog &rhs)
{
     if(this != &rhs)
     {
        this->type = rhs.type;
        this->brain = new Brain(*(rhs.brain));
     }
    std::cout << "Dog assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog Destructor called" <<std::endl;
}

void Dog::makeSound(void) const {
    std::cout << "bark" << std::endl;
}

Brain *Dog::getBrain(void) const
{
	return (this->brain);
}