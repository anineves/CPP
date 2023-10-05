#include "Zombie.hpp"

int main(void)
{

    std::string heap;
    std::string stack;

    std::cout << "The name of the heap zombie : " << std::endl;
    std::cin >> heap;
	std::cout << "The name of the stack zombie : " << std::endl;
    std::cin >> stack;

    Zombie *zombie_heap = newZombie(heap);  zombie_heap->announce();
	delete zombie_heap;  
    
	randomChump(stack);
    return (0);
}