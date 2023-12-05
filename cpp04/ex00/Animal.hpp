#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
class Animal
{
    protected:
        std::string type;

    public:
        Animal();
        Animal(Animal const &source);
        Animal &operator= (const Animal &rhs);
        virtual ~Animal();

        std::string getType(void) const;
		void setType(const std::string& type);
        virtual void makeSound() const;

};

#endif