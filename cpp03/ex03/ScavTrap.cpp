#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "Default Scav Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
    std::cout << "ScavTrap(name) Constructor called "<<std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &source): ClapTrap(source)
{
     std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &rhs)
{
    std::cout << "SvacTrap Overload assignment operator called" << std::endl;
    ClapTrap::operator=(rhs);
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" <<std::endl;
}

void	ScavTrap::attack(const std::string& target) {

    if( this->hit_points > 0 && this->energy_points > 0)
    {
        std::cout << "ScavTrap " << this->name <<" attacks " << target << " causing ";
        std::cout << this->attack_damage << " points of damage!" <<std::endl;
        this->energy_points--;
    } 
    else
    {
        std::cout << "ScavTrap " << this->name <<" doesn't have energy points or hit points." << std::endl;
    }
}

void	ScavTrap::guardGate() 
{
	 std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode!" << std::endl;
}