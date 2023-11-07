#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->fix = 0;
}

Fixed::Fixed(Fixed &source)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = source;
    //this->setRawBits(num.getRawBits());
}

Fixed& Fixed::operator = (Fixed &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
        this->fix = src.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fix);
}

void Fixed::setRawBits(int const raw)
{
    this->fix = raw;
}