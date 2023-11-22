#include "Zombie.hpp"

int main(void)
{
    int size;
    std::string name;
    std::cout << "Please enter the size of your horde zombies: " << std::endl;
    std::cout << "> ";
    std::cin >> size;
    while(size <= 0 || std::cin.fail())
    {
        std::cout << "Please choose a number higher than zero" << std::endl;
        std::cout << "> ";
        std::cin.clear();
		std::cin.ignore(1000, '\n');
        std::cin >> size;
    }
    std::cin.ignore(1000, '\n');
    std::cout << "Please enter the name of your horde zombies:" << std::endl;
    std::cout << "> ";
    std::getline(std::cin, name);
    while (name.empty())
    {
        std::cout << "Name can't be empty, pleasee choose a name " << std::endl;
        std::cout << "> ";
        std::getline(std::cin, name);
    }
    Zombie* hord = zombieHorde(size, name);
    for (int i = 0; i < size; i++)
        hord[i].announce();
    delete[] hord;
    return (0);
}