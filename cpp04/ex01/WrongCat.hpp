#ifndef WRONGCAT_HH
#define WRONGCAT_HH

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
        WrongCat();
        WrongCat(const WrongCat &source);
        WrongCat &operator = (const WrongCat &rhs);
        ~WrongCat();

        void makeSound();
};

#endif
