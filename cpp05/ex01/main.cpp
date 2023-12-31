#include "Bureaucrat.hpp"
#include "Form.hpp"
int	main()
{

    std::cout << "--------------------------ERROR-----------------------------------------" <<std::endl;
    try
    {
        std::cout << "Exemplo 1"  << std::endl;
        Bureaucrat bureaucrat1("Ana", 0);
        std::cout << bureaucrat1 <<std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    try
    {
        std::cout << "Exemplo 2"  << std::endl;
        Bureaucrat bureaucrat2("Isabel", 151);
        std::cout << bureaucrat2;
        std::
        cout<<std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
	
    try
    {
        std::cout << "Exemplo 3"  << std::endl;
        Bureaucrat bureaucrat3("Sousa", 1);
        bureaucrat3.increment();
        std::cout << bureaucrat3;
    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Exemplo 4"  << std::endl;
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
        std::cout << "Exemplo 1"  << std::endl;
        Bureaucrat bureaucrat1("Ana", 9);
        Form form ("Form", 0, 1);
        //bureaucrat1.signForm(form);
        std::cout << bureaucrat1 <<std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    try
    {
        std::cout << "Exemplo 2"  << std::endl;
        Bureaucrat bureaucrat1("Ana", 9);
        Form form ("Form", 4, 4);
        bureaucrat1.signForm(form);
        std::cout << bureaucrat1 <<std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    

    try
    {
        std::cout << "Exemplo 3"  << std::endl;
        Bureaucrat bureaucrat1("Ana", 2);
        Form form ("Form", 1, 1);
        form.beSigned(bureaucrat1);
        std::cout << bureaucrat1 <<std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Exemplo 4"  << std::endl;
        Bureaucrat bureaucrat1("Ana", 1);
        Bureaucrat bureaucrat2(bureaucrat1);
        Form form ("Form", 1, 2);
        form.beSigned(bureaucrat1);
        bureaucrat2.setGrade(2);
        std::cout << bureaucrat1;
        form.beSigned(bureaucrat2);
        //std::cout << bureaucrat2 <<std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    

    std::cout << "-----------------------No error-------------------------------------------------" <<std::endl;

    try
    {
        std::cout << "Exemplo 1"  << std::endl;
        Bureaucrat bureaucrat1("Ana", 1);
        std::cout << bureaucrat1;
    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    

    try
    {
        std::cout << "Exemplo 2"  << std::endl;
        Bureaucrat bureaucrat2("Isabel", 150);
        std::cout << bureaucrat2;
    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
	
    try
    {
        std::cout << "Exemplo 3"  << std::endl;
        Bureaucrat bureaucrat3("Sousa", 3);
        bureaucrat3.increment();
        std::cout << bureaucrat3;
    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Exemplo 4"  << std::endl;
        Bureaucrat bureaucrat4("Neves", 149);
        bureaucrat4.decrement();
        std::cout << bureaucrat4;
    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Exemplo 5"  << std::endl;
        Bureaucrat bureaucrat1("Ana", 3);
        Form form ("Form", 7, 7);
        form.beSigned(bureaucrat1);
        std::cout << bureaucrat1;
    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Exemplo 6"  << std::endl;
        Bureaucrat bureaucrat1("Ana", 3);
        Form form ("Form", 7, 7);
        bureaucrat1.signForm(form);
        std::cout << bureaucrat1;
    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

	return (0);
}
