#include "BitcoinExchange.hpp"

int main (int argc, char **argv)
{
    
    if( argc != 2)
    {
           std::cout << "Invalid args, please try ./btc input.txt" << std::endl;
        return 1;
    }   
    else
    {
        try
        {
            BitcoinExchange btc;
            btc.parseArgv(argv[1]);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    return 0;
}