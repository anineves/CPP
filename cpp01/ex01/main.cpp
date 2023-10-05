#include "Zombie.hpp"

int main(void)
{
    int size;
    std::string name;
    std::cout << "Please enter the size of your horde zombies: " << std::endl;
    std::cout << "> ";
    std::cin >> size;
    while(size <= 0)
    {
        std::cout << "Please choose a number higher than zero" << std::endl;
        std::cout << "> ";
        std::cin >> size;
    }
    std::cin.ignore();
    std::cout << "Please enter the name of your horde zombies:" << std::endl;
    std::cout << "> ";
    std::getline(std::cin, name);
    while (name.empty())
    {
        std::cout << "Name cann't be empty, pleasee choose a name " << std::endl;
        std::cout << "> ";
        std::getline(std::cin, name);
    }
    Zombie  *hord = zombieHorde(size, name);
    for (int i = 0; i < size; i++)
        hord[i].announce();
    delete[] hord;
    return (0);
}