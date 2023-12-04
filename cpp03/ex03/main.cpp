
#include "DiamondTrap.hpp"

int main( void )
{
    DiamondTrap diamond( "Ana" );

    diamond.whoAmI();

    diamond.attack( "something");
    diamond.takeDamage( 100 );
    diamond.attack( "something");

    return 0;
}