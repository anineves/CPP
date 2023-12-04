#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap("Ana");
    ClapTrap clap1("Isabel");


    clap.attack("something");
    clap.attack("something");
    clap.attack("something");
    clap.takeDamage(10);
    clap.takeDamage(9);
    clap.attack("something");
    clap.beRepaired(5);
    clap.attack("something");
    clap.attack("something");
    clap.attack("something");
    clap.attack("something");
    clap.attack("something");
    clap.attack("something");
    
    return 0;
}