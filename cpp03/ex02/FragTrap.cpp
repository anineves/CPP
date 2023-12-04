#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "Fragtrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
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

void FragTrap::highFiveGuys(void)
{
	std::cout << "FragTrap " << this->name << " high fives everybody." << std::endl;
}	
