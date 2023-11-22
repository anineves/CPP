#include "Zombie.hpp"

Zombie::Zombie()
{ 
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << this->name << " has been destroyed." << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::get_name()
{
    return (this->name);
}

void    Zombie::set_name(std::string name)
{
    this->name = name;
}