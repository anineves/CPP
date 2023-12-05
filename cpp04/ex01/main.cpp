#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
    std::cout << "-----------Subject---------------" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

    std::cout << "-----------Array-------------------------" << std::endl;
    const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
    for ( int i = 0; i < 4; i++ ) {
        
        delete animals[i];
    }

    std::cout << "---------------Deep copy------------" << std::endl;
	
	Cat *cat = new Cat();
	Cat *copy = new Cat(*cat);

	std::cout << "Cat  " << cat->getBrain() << std::endl << std::endl;
	std::cout << "Copy  " << copy->getBrain() << std::endl << std::endl;

	delete cat;
	delete copy;

    std::cout<< "--------------------------------------------"<<std::endl;
    Cat basic;
    {
        Cat tmp = basic;
        std::cout << "Cat  " << basic.getBrain() << std::endl << std::endl;
        std::cout << "Copy  " << tmp.getBrain() << std::endl << std::endl;
    }


    return 0;
}
