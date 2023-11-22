#ifndef HUMAN_B_CLASS_H
# define HUMAN_B_CLASS_H

# include "Weapon.hpp"

class	HumanB
{
	private:
		Weapon				*weapon;
		std::string const	name;

	public:
		HumanB( std::string const name);
		~HumanB();
		void	attack( ) const;
		void	setWeapon( Weapon &weapon );
};

#endif