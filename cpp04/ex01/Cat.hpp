#ifndef CAT_HH
#define CAT_HH

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
