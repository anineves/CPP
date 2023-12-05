#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("WrongAnimal")
{
    std::cout << "WrongAnimal Default constructor called " <<std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &source)
{
    *this = source;
    std::cout << " WrongAnimal Copy constructor called" << std::endl;
    return;
}

WrongAnimal&   WrongAnimal::operator=( const WrongAnimal &rhs ) {
    if(this != &rhs)
        this->type = rhs.type;
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called" <<std::endl;
}


std::string WrongAnimal::getType(void) const
{
	return (this->type);	
}

void WrongAnimal::setType(const std::string& type)
{
	this->type = type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal: undefined sound " << std::endl;
}