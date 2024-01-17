#include "RPN.hpp"

int main(int argc, char **argv) 
{
    if( argc != 2)
    {
           std::cout << "Invalid args, please try ./RPN  <expression>" << std::endl;
        return 1;
    }   
    else
    {
        try
        {
            Rpn rpn;
            std::cout << rpn.solve(argv[1]) << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    return 0;
}