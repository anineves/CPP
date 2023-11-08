#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->fix = 0;
}

Fixed::Fixed(const int f) : fix( f << fract)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : fix(std::roundf( f * (1 << fract)))
{
    std::cout << "Float constructor called" << std::endl;
} 

Fixed::Fixed(Fixed const &source)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = source;
}

Fixed& Fixed::operator = (const Fixed &src)
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

std::ostream & operator<<( std::ostream & out, Fixed const & in ) {
    out << in.toFloat();
    return out;
}