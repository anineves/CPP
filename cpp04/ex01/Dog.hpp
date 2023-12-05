#ifndef DOG_HH
#define DOG_HH

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
        Brain *getBrain(void) const;
};

#endif