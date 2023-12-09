#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

class ShrubberyCreationForm : public AForm
{
    private:
        const std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &source);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
};
#endif