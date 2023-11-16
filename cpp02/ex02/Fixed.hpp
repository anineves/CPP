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
        Fixed &operator= (const Fixed &rhs);
        bool operator> (const Fixed &rhs) const;
        bool operator< (const Fixed &rhs) const;
        bool operator>= (const Fixed &rhs) const;
        bool operator<= (const Fixed &rhs) const;
        bool operator== (const Fixed &rhs) const;
        bool operator!= (const Fixed &rhs) const;

        Fixed operator+ (const Fixed &rhs) const;
        Fixed operator- (const Fixed &rhs) const;
        Fixed operator* (const Fixed &rhs) const;
        Fixed operator/ (const Fixed &rhs) const;

        Fixed operator++ ();
        Fixed operator++ (int);
        Fixed operator-- ();
        Fixed operator-- (int) ;
     
        //destructor
        ~Fixed();
     
        //member function
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;
        static Fixed& min( Fixed &n1, Fixed &n2 );
        static const Fixed& min( const Fixed &n1, const Fixed &n2 );
        static Fixed& max( Fixed &n1, Fixed &n2 );
        static const Fixed& max( const Fixed &n1, const Fixed &n2 );      
};

std::ostream &operator<< (std::ostream &lhs, const Fixed &rhs);
#endif