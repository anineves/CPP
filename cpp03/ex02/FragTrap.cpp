#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "Default Scav Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
    std::cout << "FragTrap(name) Constructor called "<<std::endl;
}

FragTrap::FragTrap(const FragTrap &source): ClapTrap(source)
{
     std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator = (const FragTrap &rhs)
{
    std::cout << "FragTrap Overload assignment operator called" << std::endl;
    ClapTrap::operator=(rhs);
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" <<std::endl;
}

void	FragTrap::attack(const std::string& target) {

    if( this->hit_points > 0 && this->energy_points > 0)
    {
        std::cout << "FragTrap " << this->name <<" attacks " << target << " causing ";
        std::cout << this->attack_damage << " points of damage!" <<std::endl;
        this->energy_points--;
    } 
    else
    {
        std::cout << "FragTrap " << this->name <<" doesn't have energy points or hit points." << std::endl;
    }
}


void FragTrap::highFiveGuys(void)
{
	std::cout << "FragTrap " << this->name << " high fives everybody." << std::endl;
}	
