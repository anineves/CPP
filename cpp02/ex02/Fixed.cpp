#include "Fixed.hpp"

Fixed::Fixed()
{
    //std::cout << "Default constructor called" << std::endl;
    this->fix = 0;
}

Fixed::Fixed(const int i) : fix( i << fract)
{
    //std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : fix(std::roundf( f * (1 << fract)))
{
    //std::cout << "Float constructor called" << std::endl;
} 

Fixed::Fixed(Fixed const &source)
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = source;
}

Fixed& Fixed::operator= (const Fixed &rhs)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->fix = rhs.getRawBits();
    return (*this);
}


bool Fixed::operator> (const Fixed &rhs) const
{
        if(this->getRawBits() > rhs.getRawBits())
            return(true);
        else
            return(false);
}

bool Fixed::operator< (const Fixed &rhs) const
{
        if(this->getRawBits() < rhs.getRawBits())
            return(true);
        else
            return(false);
}

bool Fixed::operator>= (const Fixed &rhs) const
{
        if(this->getRawBits() >= rhs.getRawBits())
            return(true);
        else
            return(false);
}

bool Fixed::operator<= (const Fixed &rhs) const
{
        if(this->getRawBits() <= rhs.getRawBits())
            return(true);
        else
            return(false);
}

bool Fixed::operator== (const Fixed &rhs) const
{
        if(this->getRawBits() == rhs.getRawBits())
            return(true);
        else
            return(false);
}

bool Fixed::operator!= (const Fixed &rhs) const
{
        if(this->getRawBits() != rhs.getRawBits())
            return(true);
        else
            return(false);
}


Fixed Fixed::operator+ (const Fixed &rhs) const
{
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator- (const Fixed &rhs) const
{
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator* (const Fixed &rhs) const
{
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/ (const Fixed &rhs) const
{
    return Fixed(this->toFloat() / rhs.toFloat());
}


Fixed  Fixed::operator++() 
{
    ++this->fix;
    return *this;
}

Fixed   Fixed::operator++(int) 
{
    Fixed tmp( *this );
    tmp.fix = this->fix++;
    return tmp;
}

Fixed Fixed::operator--() 
{
    --this->fix;
    return *this;
}

Fixed Fixed::operator--(int) 
{
    Fixed tmp( *this );
    tmp.fix = this->fix--;
    return tmp;
}



Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
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


Fixed& Fixed::min (Fixed& n1, Fixed& n2)
{	
    if( n1 < n2)
        return(n1);
	else
        return (n2);
}


const Fixed& Fixed::min (const Fixed &n1, const Fixed &n2)
{	
    if( n1 < n2)
        return(n1);
	else
        return (n2);
}

Fixed& Fixed::max (Fixed& n1, Fixed& n2)
{	
    if( n1 > n2)
        return(n1);
	else
        return (n2);
}


const Fixed& Fixed::max (const Fixed &n1, const Fixed &n2)
{	
    if( n1 > n2)
        return(n1);
	else
        return (n2);
}

