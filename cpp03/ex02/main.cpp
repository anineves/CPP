#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ScavTrap scav("Ana");
    ClapTrap clap("Neves");
    FragTrap frag ("Isabel");

    scav.attack("knife");
    clap.attack("gun");
    frag.attack("other");
    clap.takeDamage(10);
    scav.takeDamage(10);
    frag.takeDamage(10);
    clap.attack("gun");
    scav.attack("gun");
    frag.attack("other");
    scav.guardGate();
    frag.highFiveGuys();
    return 0;
}