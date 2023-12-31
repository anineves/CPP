#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
        private:
                Brain *brain;
	public:
        Cat();
        Cat(const Cat &source);
        Cat &operator = (const Cat &rhs);
        ~Cat();

        void makeSound() const;
        Brain *getBrain(void) const;
};

#endif
