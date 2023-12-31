#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade)
{
        if (grade < 1)
            throw Bureaucrat::GradeTooHighException();
        if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
        this->grade = grade;
   
}

Bureaucrat::Bureaucrat(const Bureaucrat &source) : name(source.name)
{
    *this= source;
    return ;
}

Bureaucrat &Bureaucrat::operator= (const Bureaucrat &rhs)
{
    if(this != &rhs)
    {
        grade= rhs.grade;
    }
    return *this;

}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName()const
{
    return (this->name);
}

int Bureaucrat::getGrade()const
{
    return (this->grade);
}

void Bureaucrat::setGrade(int new_grade)
{
    this->grade = new_grade;
}

void Bureaucrat::decrement()
{
        if(this->grade + 1 > 150)
            throw Bureaucrat::GradeTooLowException();
        this->grade++;
        std::cout<<"Decrement"<<std::endl;
    
}

void Bureaucrat::increment()
{
    if((this->grade - 1) < 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
    std::cout<<"Increment"<<std::endl;
}


const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("The grade is too high");
}


const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("The grade is too low");
}

void Bureaucrat::signForm(Form &form) 
{
    try
    {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << this->name << " couldn't sign" << form.getName() << " because "<< e.what() << std::endl;
    }
    
} 

std::ostream &operator<< (std::ostream &lhs, Bureaucrat const &rhs)
{
    lhs<< rhs.getName() << ", bureaucrat grade " << rhs.getGrade()<<"."<<std::endl;
    return(lhs);
}
