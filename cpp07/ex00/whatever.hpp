#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>

template <typename T>
void swap(T &x, T &y) 
{
    //std::cout << "swap" <<std::endl;
    T tmp = x;
    x = y;
    y = tmp;
}

template <typename T>
T min(T x, T y) 
{
    //std::cout << "\nmin" <<std::endl;
    if( x < y)
        return(x);
    else
        return (y);
}

template <typename T>
T max(T x, T y) 
{
    //std::cout << "\nmax" <<std::endl;
     if( x > y)
        return(x);
    else
        return (y);
}

#endif 
