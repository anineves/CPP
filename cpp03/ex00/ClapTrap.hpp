#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
class ClapTrap
{
    private:
        std::string name;
        int   hit_points;
        int   energy_points;
        int   attack_damage;

    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const &source);
        ClapTrap &operator= (const ClapTrap &rhs);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

};

#endif