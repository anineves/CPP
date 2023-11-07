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
        Fixed(const int f);
        Fixed(const float f);
        //copy constructor
        Fixed(Fixed const &source);
        //destructor
        ~Fixed();
        //member function
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;
        //operator overload
        Fixed& operator= (Fixed const &src);
};


std::ostream& operator<<(std::ostream& out, const Fixed& in);
#endif