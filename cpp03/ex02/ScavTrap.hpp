#ifndef SCAVTRAP_HH
#define SCAVTRAP_HH

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &source);
        ScavTrap &operator = (const ScavTrap &rhs);
        ~ScavTrap();

        void attack(const std::string& target);
		void guardGate();
};

#endif
