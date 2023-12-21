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
    try
    {
        Bureaucrat bureaucrat1("Ana", 9);
        //AForm form ("Form", 0, 0);
        //bureaucrat1.signForm(form);
        std::cout << bureaucrat1 <<std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "-----------------------No error-------------------------------------------------" <<std::endl;

    try
    {
        std::cout<< "teste 1" << std::endl;
        Bureaucrat bureaucrat1("Ana", 100);
        ShrubberyCreationForm form("Home");
        RobotomyRequestForm  form2("Home");
        PresidentialPardonForm form3("Home");
        form.executeFormAction();
        bureaucrat1.signForm(form);
        std::cout << std::endl;
        form2.executeFormAction();
        bureaucrat1.signForm(form2);
        std::cout << std::endl;
        form3.executeFormAction();
        bureaucrat1.signForm(form3);
        std::cout << bureaucrat1;
    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    

    try
    {
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout<< "teste 2" << std::endl;
        Bureaucrat bureaucrat1("Ana", 4);
        ShrubberyCreationForm form("Home");
        RobotomyRequestForm  form2("Home");
        PresidentialPardonForm form3("Home");
        bureaucrat1.signForm(form);
        form.execute(bureaucrat1);
        std::cout << std::endl;
        bureaucrat1.signForm(form2);
        form2.execute(bureaucrat1);
        std::cout << std::endl;
        bureaucrat1.signForm(form3);
        form3.execute(bureaucrat1);
        std::cout << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }


    try
    {
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout<< "teste 3" << std::endl;
        Bureaucrat bureaucrat1("Ana", 40);
        ShrubberyCreationForm form("Home");
        RobotomyRequestForm  form2("Home");
        PresidentialPardonForm form3("Home");
        bureaucrat1.signForm(form);
        bureaucrat1.executeForm(form);
        std::cout << std::endl;
        bureaucrat1.signForm(form2);
        bureaucrat1.executeForm(form2);
        std::cout << std::endl;
        bureaucrat1.signForm(form3);
        bureaucrat1.executeForm(form3);
        std::cout << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }


	return (0);
}
