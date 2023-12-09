#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool sign;
        const int gradeSign;
        const int gradeExec;

    public:
        Form();
        Form(const std::string &name, int gradeSign, int gradeExec);
        Form(Form const &source);
        Form &operator=(Form const &rhs);
        ~Form();

        std::string getName() const;
        bool getSign() const;
        int getGradeSign() const;
        int getGradeExec() const;

        void beSigned(const Bureaucrat &b1);

        class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw(); 
        };

};

std::ostream &operator<<(std::ostream &lhs, const Form &rhs);

#endif