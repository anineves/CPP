#include "Harl.hpp"

Harl :: Harl(void)
{

}

Harl :: ~Harl(void)
{

}

void Harl::complain (std::string level)
{
	typedef void ( Harl::*func )( void );

	std::string choice[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    func funcs[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int i = 0; i < 4; i++)
    {
        if (level == choice[i])
        {
            (this->*funcs[i])();
            return ;
        }
    }
    std::cerr << "Wrong input" << std::endl;	
}
void Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my" \
		"7XL-double-cheese-triple-pickle-special-ketchup burger.\n"\
		"I really do!" << std::endl;
	std::cout << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl ;
	std::cout << "I cannot believe adding extra bacon costs more money.\n"\
		"You didn't put enough bacon in my burger! \n"\
		"If you did, I wouldn't be asking for more!" << std::endl;
	std::cout << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. \n"\
		"I've been coming for years whereas you started working here since last month." << std::endl;
	std::cout << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

