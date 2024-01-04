#include "iter.hpp"

int main( void )
{
    int arrInt[] = { 0, 1, 2, 3, 4};
    std::cout << "arrInt: " << std::endl;
    iter(arrInt, 5, printt<int>);
    std::cout << "-------------------------------------------- " << std::endl;
    
    char arrChar[] = { 'a', 'b', 'c', 'd'};
    std::cout << "arrChar: " << std::endl;
    iter(arrChar, 4, printt<char>);
    std::cout << "-------------------------------------------- " << std::endl;

    std::string arrString[] = { "Ana", "Isabel", "Neves"};
    std::cout << "arrString: " << std::endl;
    iter(arrString, 3, printt<std::string >);
    std::cout << "-------------------------------------------- " << std::endl;
    
    double arrDouble[] = { 1.1, 1.2, 1.3, 1.4, 1.5 };
    std::cout << "arrDouble: " << std::endl;
    iter(arrDouble, 5, printt<double>);
   

    return 0;
}
