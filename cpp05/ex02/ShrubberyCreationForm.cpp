#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm() 
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubbery", 145, 137), target(target) 
{
    
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : AForm(src) 
{

}

ShrubberyCreationForm::~ShrubberyCreationForm() 
{

}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) 
{
    if (this != &rhs)
        AForm::operator=(rhs);

    return *this;
}