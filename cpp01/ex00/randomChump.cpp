#include "Zombie.hpp"

void    randomChump(std::string name)
{
    Zombie zombie_stack = Zombie();
    zombie_stack.set_name(name);
    zombie_stack.announce(); 
}