#ifndef HUMAN_B_CLASS_H
# define HUMAN_B_CLASS_H

# include "Weapon.hpp"

class	HumanB
{
	private:
		Weapon				*_weapon;
		std::string const	_name;

	public:
		HumanB( std::string const name);
		~HumanB();
		void	attack( ) const;
		void	setWeapon( Weapon &weapon );
};

#endif