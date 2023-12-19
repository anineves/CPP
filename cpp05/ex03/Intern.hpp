#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm; 

class Intern
{
    public:
        Intern();
        Intern(const std::string &target);
        Intern( const Intern&source);
        Intern&operator= (const Intern&rhs);
        ~Intern();

        AForm *makeForm(std::string &formName, std::string &targetForm);
        AForm *PresidentialPardon(const std::string &target);
		AForm *RobotomyRequest(const std::string &target);
		AForm *ShrubberyCreation(const std::string &target);
};

#endif