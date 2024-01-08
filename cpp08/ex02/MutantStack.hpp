#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <iostream>
# include <stack>
# include <list>


template <typename T, class C = std::deque<T> >
class MutantStack : public std::stack<T, C>
{
	public:
		MutantStack() {}
		MutantStack(const MutantStack& source) { *this = source; }
		MutantStack& operator=(const MutantStack& rhs) 
		{
			if (this != &rhs) 
            {
                std::stack<T>::operator=(rhs);
            }
            return *this;
		}
		~MutantStack() {}

		typedef typename C::iterator iterator;

		iterator begin(void)
        { return (this->c.begin()); }
		iterator end(void) 
        { return (this->c.end()); }
};

#endif