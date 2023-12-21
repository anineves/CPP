#include "RobotomyRequestForm.hpp"
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("target") 
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) 
{
    
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
    : AForm(src) 
{

}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) 
{
    if (this != &rhs)
        AForm::operator=(rhs);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() 
{
}


void RobotomyRequestForm::executeFormAction() const
{
    std::cout << ".........Imagine some drilling noises......"<<std::endl;

    srand(time(NULL));

    int sucess = rand() %2;
    try
    {
        if(sucess == 0)
            throw RobotomyRequestForm::RobotomizedFailException();
        std::cout << this->target << " has been robotomized" << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout<<e.what() << std::endl;
    }

}
