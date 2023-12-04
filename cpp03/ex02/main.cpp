#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ScavTrap scav("Ana");
    ClapTrap clap("Neves");
    FragTrap frag ("Isabel");
    FragTrap frag2;

    frag2= frag;
    scav.attack("something");
    clap.attack("something");
    frag.attack("something");
    clap.takeDamage(10);
    scav.takeDamage(10);
    frag.takeDamage(10);
    frag2.takeDamage(10);
    frag2.attack("something");
    clap.attack("something");
    scav.attack("something");
    frag.attack("other thing");
    scav.guardGate();
    frag.highFiveGuys();
    return 0;
}