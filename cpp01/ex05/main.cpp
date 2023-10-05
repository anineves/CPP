#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;
	std::string level;
	
	if (argc != 2) 
	{
        	std::cerr << "Wrong Input, \n Please try again, with ./harl <level> " << std::endl;
        	return (1);
    	}
	level = argv[1];
	harl.complain(level);
	return (0);
}
