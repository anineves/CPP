#include "PMergeMe.hpp"

PMergeMe::PMergeMe()
{

}

PMergeMe::PMergeMe(const PMergeMe &source)
{
    *this = source;
}

PMergeMe &PMergeMe::operator=(const PMergeMe &rhs)
{
    (void) rhs;
    return(*this);
}

PMergeMe::~PMergeMe() {}