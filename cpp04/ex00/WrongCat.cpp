#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
	std::cout << "WrongCat Default Constructor called" << std::endl;
}


WrongCat::WrongCat(const WrongCat &source): WrongAnimal(source)
{
     std::cout << "WrongCat Copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator = (const WrongCat &rhs)
{
     if(this != &rhs)
        this->type = rhs.type;
    std::cout << "WrongCat assignment operator called" << std::endl;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called" <<std::endl;
}

void WrongCat::makeSound()
{
    std::cout << "wrong miau" << std::endl;
}