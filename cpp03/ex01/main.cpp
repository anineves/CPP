#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap scav("Ana");
    ScavTrap scav1("Isabel");
    ClapTrap clap("Neves");

    scav.attack("something");
    scav1.attack("something");
    clap.attack("something");
    clap.takeDamage(10);
    scav.takeDamage(10);
    clap.attack("something");
    scav.attack("something");
    scav.guardGate();
    return 0;
}