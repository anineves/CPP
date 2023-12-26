#include <cstdlib>
#include <ctime>
#include "Base.hpp"

int main() 
{
    Base *b = generate();
    identify(b);
    identify(*b);

    Base *b1 = NULL;

    identify(b1);
    identify(*b1);

    delete b;

    return 0;
}