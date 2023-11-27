#include "Zombie.hpp"

void    randomChump(std::string name)
{
    Zombie zombie_stack = Zombie(name);
    zombie_stack.announce(); 
}