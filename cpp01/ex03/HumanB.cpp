#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) , weapon(nullptr) 
{
}

HumanB::~HumanB() 
{
}

void    HumanB::attack(void) const
{
    if (this->weapon == NULL)
    {
        std::cout << this->name << " attacks with no weapon " << std::endl;
    }
    else
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}