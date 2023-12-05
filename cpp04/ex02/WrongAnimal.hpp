#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
class WrongAnimal
{
    protected:
        std::string type;

    public:
        WrongAnimal();
        WrongAnimal(WrongAnimal const &source);
        WrongAnimal &operator= (const WrongAnimal &rhs);
        virtual ~WrongAnimal();

        std::string getType(void) const;
		void setType(const std::string& type);
        void makeSound() const;

};

#endif