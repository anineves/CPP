#include "Zombie.hpp"

Zombie::Zombie()
{ 
}

Zombie::~Zombie()
{

}

void    Zombie::announce(void)
{
    std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::get_name()
{
    return (this->_name);
}

void    Zombie::set_name(std::string name)
{
    this->_name = name;
}