#include "Form.hpp"

Form::Form() : name("default"), gradeSign(0), gradeExec(0)
{
    throw Form::GradeTooHighException();
}

Form::Form(const std::string &name, int gradeSign, int gradeExec) : name(name), gradeSign(gradeSign), gradeExec(gradeExec)
{
    if(gradeSign  < 1 || gradeExec < 1)
        throw Form::GradeTooHighException();
    if(gradeExec > 150 || gradeExec > 150)
        throw Form::GradeTooLowException();
}


Form::Form(const Form &source) : name(source.name), gradeSign(source.gradeSign), gradeExec(source.gradeExec)
{
    this->sign = source.sign;
    return ;
}

Form &Form::operator=(const Form &rhs)
{
    if(this != &rhs)
    {
        this->sign = rhs.sign;
    }

    return *this;
}

Form::~Form()
{
    
}

std::string Form::getName() const
{
    return (this->name);
}

bool Form::getSign() const
{
    return (this->sign);
}

int Form::getGradeSign() const 
{
    return (this->gradeSign);
}

int Form::getGradeExec() const
{
    return (this->gradeExec);
}

void Form::beSigned(const Bureaucrat &b1)
{
    if(b1.getGrade() > this->gradeSign)
    {
        throw Form::GradeTooLowException();
    }
    this->sign = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("The grade is too high");
}


const char * Form::GradeTooLowException::what() const throw()
{
    return ("The grade is too low");
}

std::ostream &operator<<(std::ostream &lhs, Form const &rhs) {
    lhs << "Form " << rhs.getName() << ", signed: " << rhs.getSign()
      << ", grade to sign: " << rhs.getGradeSign()
      << ", grade to execute: " << rhs.getGradeExec() << std::endl;

    return lhs;
}