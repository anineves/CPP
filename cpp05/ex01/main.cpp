#include "Bureaucrat.hpp"
#include "Form.hpp"
int	main()
{

    /*std::cout << "--------------------------ERROR-----------------------------------------" <<std::endl;
    try{
        Bureaucrat bureaucrat1("Ana", 0);
        std::cout << bureaucrat1 <<std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    

    try{
        Bureaucrat bureaucrat2("Isabel", 151);
        std::cout << bureaucrat2;
        std::
        cout<<std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
	
    try{
    Bureaucrat bureaucrat3("Sousa", 1);
	bureaucrat3.increment();
	std::cout << bureaucrat3;
    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try{
	Bureaucrat bureaucrat4("Neves", 150);
	bureaucrat4.decrement();
	std::cout << bureaucrat4;
    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }


    std::cout << "-----------------------No error-------------------------------------------------" <<std::endl;

    try{
        Bureaucrat bureaucrat1("Ana", 1);
        std::cout << bureaucrat1;
    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    

    try{
        Bureaucrat bureaucrat2("Isabel", 150);
        std::cout << bureaucrat2;
    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
	
    try{
        Bureaucrat bureaucrat3("Sousa", 3);
        bureaucrat3.increment();
        std::cout << bureaucrat3;
    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try{
        Bureaucrat bureaucrat4("Neves", 149);
        bureaucrat4.decrement();
        std::cout << bureaucrat4;
    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
	return (0);*/

     std::cout << "Tests with (*) at the begining should print an exception"
              << std::endl
              << std::endl;

    /* ------------------------------------ */

    std::cout << "TEST 1) Valid Form and signable" << std::endl;
    try {
        Bureaucrat bur("John", 9);
        Form form("TC39", 0, 0);
        bur.signForm(form);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}