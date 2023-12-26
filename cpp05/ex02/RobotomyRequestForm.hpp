#ifndef ROBOTMYREQUESTFORM_HPP
#define ROBOTMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
            const std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm( const RobotomyRequestForm &source);
        RobotomyRequestForm &operator= (const RobotomyRequestForm &rhs);
        ~RobotomyRequestForm();

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
