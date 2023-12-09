#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool sign;
        const int gradeSign;
        const int gradeExec;

    public:
        AForm();
        AForm(const std::string &name, int gradeSign, int gradeExec);
        AForm(AForm const &source);
        AForm &operator=(AForm const &rhs);
        ~AForm();

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

std::ostream &operator<<(std::ostream &lhs, const AForm &rhs);

#endif
