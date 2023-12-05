#include "Brain.hpp"
#include "Animal.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; i++) 
    {
        this->ideas[i] = "Animal has no idea";
    }
	std::cout << "Brain Default Constructor called" << std::endl;
}


Brain::Brain(const Brain &source)
{
    *this = source;
    std::cout << "Brain Copy constructor called" << std::endl;
}

Brain &Brain::operator = (const Brain &rhs)
{
      if (this != &rhs) 
      {
        for (int i = 0; i < 100; i++) 
        {
            this->ideas[i] = rhs.ideas[i];
        }
      }
    std::cout << "Brain assignment operator called" << std::endl;
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called" <<std::endl;
}

void Brain::show() const 
{
    for (int i = 0; i < 100; i++) 
    {
        std::cout << i << ":" << this->ideas[i] << std::endl;
    }
}

