#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap("Ana");
    ClapTrap clap1("Isabel");
	ClapTrap clap_op;
    ClapTrap clap_copy(clap1);


    clap.attack("knife");
    
    clap_op = clap1;
    clap1.attack("gun");
    clap_op.attack("gun");
    clap_copy.attack("gun");
    clap1.takeDamage(10);
    clap1.attack("gun");
    clap_op.attack("gun");
    return 0;
}