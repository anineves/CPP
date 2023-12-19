#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    
    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(Bureaucrat const &source);
        Bureaucrat &operator = (const Bureaucrat &rhs);
        ~Bureaucrat();


        std::string getName() const;
        int getGrade() const;
        void setGrade(int new_grade);

        void increment();
        void decrement();

        class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw(); 
        };
        void signForm(AForm &form);
        void executeForm(AForm const &form);
};

std::ostream &operator<<(std::ostream &lhs, const Bureaucrat &rhs);

#endif
