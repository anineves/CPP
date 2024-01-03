#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
void easyfind(T &value1, int value2) 
{


    if (std::find(value1.begin(), value1.end(), value2) != value1.end())
    {
        std::cout << "Found." << std::endl;
    }
    else
        std::cout << "Not found." << std::endl;
}

#endif
