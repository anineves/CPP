#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <fstream>
#include <cmath>

class Fixed
{
    private:
        int fix;
        static const int fract = 8;
        
    
    public:
        //constructor 
        Fixed();
        Fixed(const int i);
        Fixed(const float f);
        //copy constructor
        Fixed(Fixed const &source);
        //operator overload
        Fixed &operator= (Fixed const &rhs);
        //destructor
        ~Fixed();
        //member function
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;
        
};


std::ostream &operator<< (std::ostream &lhs, const Fixed &rhs);
#endif