#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(name)
{
	this->name = name +"_clap_name";
	std::cout << "Diamond "<< this->name << " Constructor called" <<std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name)
{
	this->name = name +"_clap_name";
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << "DiamondTrap " << this->name << "(name) Constructor called" <<std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &source): ClapTrap(source), FragTrap(source), ScavTrap(source)
{
	std::cout << "DiamondTrap Copy constructor called"<<std::endl;
}

DiamondTrap &DiamondTrap::operator = (const DiamondTrap &rhs)
{
	if(this != &rhs)
    {
        this->name = rhs.name;
        this->hit_points = rhs.hit_points;
        this->energy_points = rhs.energy_points;
        this->attack_damage = rhs.attack_damage;
    }
    std::cout << "Diamond Assignment operator called" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->name << " destroyed." <<std::endl;
}

void DiamondTrap::whoAmI()
{
		std::cout << "WhoAmI: DiamondTrap: " << this->name << std::endl;
		std::cout << "WhoAmI: Claptrap: " << ClapTrap::name << std::endl;
}