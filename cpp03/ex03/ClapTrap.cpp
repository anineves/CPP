#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("default"), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "Default constructor called " <<std::endl;
}

ClapTrap::ClapTrap(std::string name): name(name), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "(name) Constructor called " <<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &source)
{
    *this = source;
    std::cout << "Copy constructor called" << std::endl;
    return;
}

ClapTrap&   ClapTrap::operator=( const ClapTrap &rhs ) {

    if(this != &rhs)
    {
        this->name = rhs.name;
        this->hit_points = rhs.hit_points;
        this->energy_points = rhs.energy_points;
        this->attack_damage = rhs.attack_damage;
    }
    std::cout << "Overload assignment operator called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" <<std::endl;
}


void ClapTrap::attack(const std::string& target)
{
    if( this->hit_points > 0 && this->energy_points > 0)
    {
        std::cout << "ClapTrap " << this->name <<" attacks " << target << " causing ";
        std::cout << this->attack_damage << " points of damage!" <<std::endl;
        this->energy_points--;
    } 
    else
    {
        std::cout << "ClapTrap " << this->name <<" doesn't have energy points or hit points." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if( this->hit_points > 0)
    {
        std::cout << "ClapTrap " << this->name << " was attacked and lost ";
        std::cout << amount << " hitpoints!" << std::endl;
        this->hit_points = this->hit_points - amount;
    }
    else
    {
        std::cout << "ClapTrap " << this->name << "doesn't have hit points." <<std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if( this->energy_points > 0 && this->hit_points > 0)
    {
        std::cout << "ClapTrap " << this->name << " repaired " << amount << " hit points" << std::endl;
        this->hit_points = this->hit_points + amount;
        this->energy_points--;
    }
    if (this->hit_points <= 0)
    {
        std::cout << "ClapTrap " << this->name << "doesn't have energy points or hit points." <<std::endl;
    }
}