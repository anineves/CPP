#include "PresidentialPardonForm.hpp"
#include <stdlib.h>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("target") 
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), target(target) 
{
    
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
    : AForm(src) 
{

}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) 
{
    if (this != &rhs)
        AForm::operator=(rhs);
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() 
{
}


void PresidentialPardonForm::executeFormAction() const
{
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox " << std::endl;
}
