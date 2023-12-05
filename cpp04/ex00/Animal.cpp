#include "Animal.hpp"

Animal::Animal(): type("Animal")
{
    std::cout << "Animal Default constructor called " <<std::endl;
}

Animal::Animal(const Animal &source)
{
    *this = source;
    std::cout << " Animal Copy constructor called" << std::endl;
    return;
}

Animal&   Animal::operator=( const Animal &rhs ) {
    if(this != &rhs)
        this->type = rhs.type;
    std::cout << "Animal assignment operator called" << std::endl;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" <<std::endl;
}


std::string Animal::getType(void) const
{
	return (this->type);	
}

void Animal::setType(const std::string& type)
{
	this->type = type;
}

void Animal::makeSound() const
{
	std::cout << "Animal: undefined sound " << std::endl;
}