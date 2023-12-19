#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{

    std::cout << "--------------------------ERROR-----------------------------------------" <<std::endl;
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

std::cout << "--------------------------ERROR Form-----------------------------------------" <<std::endl;
    try{
        Bureaucrat bureaucrat1("Ana", 9);
        //Form form ("Form", 0, 0);
        //bureaucrat1.signForm(form);
        std::cout << bureaucrat1 <<std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    

    try{
        Bureaucrat bureaucrat1("Ana", 2);
        //Form form ("Form", 1, 1);
        //form.beSigned(bureaucrat1);
        std::cout << bureaucrat1 <<std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try{
        Bureaucrat bureaucrat1("Ana", 1);
        Bureaucrat bureaucrat2(bureaucrat1);
        //Form form ("Form", 1, 2);
        //form.beSigned(bureaucrat1);
        std::cout << bureaucrat1;
        bureaucrat2.setGrade(2);
        //form.beSigned(bureaucrat2);
        std::cout << bureaucrat2 <<std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    

    std::cout << "-----------------------No error-------------------------------------------------" <<std::endl;

    try{
        Bureaucrat bureaucrat1("Ana", 1);
        ShrubberyCreationForm form("Home");
        RobotomyRequestForm  form2("Home");
        PresidentialPardonForm form3("Home");
        form.executeFormAction();
        form2.executeFormAction();
        form3.executeFormAction();
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
	return (0);

 
    std::cout << std::endl;
}
