#include "easyfind.hpp"

int main()
{
    std::vector<int> vect;

    vect.push_back(1);
    vect.push_back(2);
    vect.push_back(3);
    vect.push_back(4);
    vect.push_back(5);

    easyfind(vect, 5);
    int num1 = 42;
    easyfind(vect, num1);
    vect.push_back(42);
    easyfind(vect, num1);
    int num2 = 500;
    easyfind(vect, num2);

    return 0;
}
