#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("default"), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "ClapTrap Default constructor called " <<std::endl;
}

ClapTrap::ClapTrap(std::string name): name(name), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << " Clap Trap (name) Constructor called " << this->name <<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &source)
{
    *this = source;
    std::cout << "ClapTrap Copy constructor called" << std::endl;
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
    std::cout << "ClapTrap Assignment operator called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called" <<std::endl;
}


void ClapTrap::attack(const std::string& target)
{
    if(this->hit_points == 0) 
    {
        std::cout << "ClapTrap " << this->name << " is dead. He can't do anything" << std::endl;
        return;
    }
    if( this->hit_points > 0 && this->energy_points > 0)
    {
        std::cout << "ClapTrap " << this->name <<" attacks " << target << " causing ";
        std::cout << this->attack_damage << " points of damage!" <<std::endl;
        this->energy_points--;
    }
    else
    {
        std::cout << "ClapTrap " << this->name <<" doesn't have energy points." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(this->hit_points == 0) 
    {
        std::cout << "ClapTrap " << this->name << " is dead. He can't be attacked" << std::endl;
        return;
    }
    if( this->hit_points > 0)
    {
        std::cout << "ClapTrap " << this->name << " was attacked and lost ";
        std::cout << amount << " hitpoints!" << std::endl;
        if (amount >= (unsigned int)this->hit_points)
        {
            this->hit_points = 0;
            std::cout << "ClapTrap " << this->name << " died." << std::endl;
        }
        else
            this->hit_points -= amount;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(this->hit_points == 0) 
    {
        std::cout << "ClapTrap " << this->name << " is dead. He can't do anything" << std::endl;
        return;
    }
    if( this->energy_points > 0 && this->hit_points > 0)
    {
        std::cout << "ClapTrap " << this->name << " repaired " << amount << " hit points" << std::endl;
        this->hit_points = this->hit_points + amount;
        this->energy_points--;
    }
    else
    {
        std::cout << "ClapTrap " << this->name << "doesn't have energy points." <<std::endl;
    }
}