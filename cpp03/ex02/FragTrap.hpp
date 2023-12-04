#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

	public:
		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( FragTrap const & source );
		~FragTrap( );
		FragTrap	&operator=( FragTrap const & rhs );
		void	highFiveGuys( void );
};
#endif 