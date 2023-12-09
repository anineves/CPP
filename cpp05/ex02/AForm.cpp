#include "AForm.hpp"

AForm::AForm() : name("default"), sign(false), gradeSign(0), gradeExec(0)
{
    throw AForm::GradeTooHighException();
}

AForm::AForm(const std::string &name, int gradeSign, int gradeExec) : name(name), sign(false), gradeSign(gradeSign), gradeExec(gradeExec)
{
    if(gradeSign  < 1 || gradeExec < 1)
        throw AForm::GradeTooHighException();
    if(gradeExec > 150 || gradeExec > 150)
        throw AForm::GradeTooLowException();
}


AForm::AForm(const AForm &source) : name(source.name), gradeSign(source.gradeSign), gradeExec(source.gradeExec)
{
    this->sign = source.sign;
    return ;
}

AForm &AForm::operator=(const AForm &rhs)
{
    if(this != &rhs)
    {
        this->sign = rhs.sign;
    }
    return *this;
}

AForm::~AForm()
{
    
}

std::string AForm::getName() const
{
    return (this->name);
}

bool AForm::getSign() const
{
    return (this->sign);
}

int AForm::getGradeSign() const 
{
    return (this->gradeSign);
}

int AForm::getGradeExec() const
{
    return (this->gradeExec);
}

void AForm::beSigned(const Bureaucrat &b1)
{
    if(b1.getGrade() > this->gradeSign)
    {
        throw AForm::GradeTooLowException();
    }
    this->sign = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("The grade is too high");
}


const char * AForm::GradeTooLowException::what() const throw()
{
    return ("The grade is too low");
}

std::ostream &operator<<(std::ostream &lhs, AForm const &rhs) {
    lhs << "Aform " << rhs.getName() << ", signed: " << rhs.getSign()
      << ", grade to sign: " << rhs.getGradeSign()
      << ", grade to execute: " << rhs.getGradeExec() << std::endl;

    return lhs;
}
