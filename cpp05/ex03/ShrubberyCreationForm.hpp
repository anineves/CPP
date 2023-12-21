#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
        const std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &source);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
        ~ShrubberyCreationForm();

        virtual void executeFormAction() const;

        class OpenShrubberyException: public std::exception {
        public:
            virtual const char* what() const throw()
            {
                return "Error to open Shrubbery File ";
            }
        };
};
#endif
