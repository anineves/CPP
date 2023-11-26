#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap scav("Ana");
    ScavTrap scav1("Isabel");
    ClapTrap clap("Neves");

    scav.attack("knife");
    scav1.attack("gun");
    clap.attack("gun");
    clap.takeDamage(10);
    scav.takeDamage(10);
    clap.attack("gun");
    scav.attack("gun");
    scav.guardGate();
    return 0;
}