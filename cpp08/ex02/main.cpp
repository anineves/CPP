#include "MutantStack.hpp"
#include <iostream>

int main()
{
    std::cout << "-------------Subject Test-----------" << std::endl;


        MutantStack<int> mstack;
       
        mstack.push(5);
        mstack.push(17);
       
        std::cout << mstack.top() << std::endl;
       
        mstack.pop();
       
        std::cout << mstack.size() << std::endl;
       
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
       
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
       
        ++it;
        --it;
       
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
   

    std::cout << "\n\n ------------List Test-----------" << std::endl;

    std::list<int> mlist;

    mlist.push_back(5);
    mlist.push_back(17);

    std::cout << mlist.back() << std::endl;

    mlist.pop_back();

    std::cout << mlist.size() << std::endl;

    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);

    std::list<int>::iterator it_mlist = mlist.begin();
    std::list<int>::iterator ite_mlist = mlist.end();

    ++it_mlist;
    --it_mlist;
    while (it_mlist!=ite_mlist)
    {
        std::cout << *it_mlist<< std::endl;
        ++it_mlist;
    }
    std::list<int> l(mlist);

    return 0;
}