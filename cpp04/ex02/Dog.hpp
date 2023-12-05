#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
    private:
        Brain *brain;
	public:
        Dog();
        Dog(std::string name);
        Dog(const Dog &source);
        Dog &operator = (const Dog &rhs);
        ~Dog();

		void makeSound(void) const;
};

#endif