#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
        const std::string target;
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm( const PresidentialPardonForm &source);
    PresidentialPardonForm &operator= (const PresidentialPardonForm &rhs);
    ~PresidentialPardonForm();

    virtual void executeFormAction() const;

    class RobotomizedFailException: public std::exception {
        public:
            virtual const char* what() const throw()
            {
                return "I can't Robotomized ";
            }
        };
};

#endif