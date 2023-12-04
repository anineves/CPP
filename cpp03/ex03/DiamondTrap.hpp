#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
	private:
		std::string name;
	public:
		DiamondTrap(void);
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap &source);
        DiamondTrap &operator = (const DiamondTrap &rhs);
        ~DiamondTrap();

		void whoAmI();
		//void attack(std::string const &target);
		using ScavTrap::attack;
};

#endif
