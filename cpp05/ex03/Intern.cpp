#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() 
{

}

Intern::Intern(const Intern &source) 
{ 
    *this = source; 
}

Intern &Intern::operator=(const Intern &rhs) 
{
    (void)rhs;
    return *this;
}

Intern::~Intern() 
{

}

AForm *Intern::PresidentialPardon(const std::string &target) 
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::RobotomyRequest(const std::string &target) 
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::ShrubberyCreation(const std::string &target) 
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string formTarget) 
{

    AForm *(Intern::*memberFuncs[])(const std::string &target) = {
        &Intern::PresidentialPardon, &Intern::RobotomyRequest, &Intern::ShrubberyCreation};

    std::string formTypes[] = {"Presidential Pardon", "Robotomy Request", "Shrubbery Creation"};

    for (int i = 0; i < 3; i++) 
    {
        if (formName == formTypes[i]) 
        {
            std::cout << "Create: " << formName << " form" << std::endl;
            return ((this->*memberFuncs[i])(formTarget));
        }
    }
    std::cout << "Form passed as parameter doesn’t exist" << std::endl;
    return (NULL);
}
