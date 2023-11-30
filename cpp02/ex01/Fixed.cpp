#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->fix = 0;
}

Fixed::Fixed(const int i) : fix( i << fract)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : fix(roundf( f * (1 << fract)))
{
    std::cout << "Float constructor called" << std::endl;
} 

Fixed::Fixed(Fixed const &source)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = source;
}

Fixed& Fixed::operator= (const Fixed &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->fix = rhs.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return (this->fix);
}

void Fixed::setRawBits(int const raw)
{
    this->fix = raw;
}

float   Fixed::toFloat( void ) const {
    return ((float)this->fix / (float) (1 << fract));
}

int     Fixed::toInt( void ) const {
    return this->fix >> fract;
}

std::ostream &operator<< (std::ostream &lhs, Fixed const &rhs) {
    lhs << rhs.toFloat();
    return lhs;
}
