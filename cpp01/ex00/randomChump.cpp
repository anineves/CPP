#include "Zombie.hpp"

void    randomChump(std::string name)
{
    Zombie zombiee = Zombie();
    zombiee.set_name(name);
    zombiee.announce(); 
}