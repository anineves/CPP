#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int fix;
        static const int fract = 8;
    
    public:
        //constructor 
        Fixed();
        //copy constructor
        Fixed(Fixed &source);
        //operator overload
        Fixed& operator= (Fixed &src);
        //destructor
        ~Fixed();
        //member function
        int getRawBits(void) const;
        void setRawBits(int const raw);
};
#endif