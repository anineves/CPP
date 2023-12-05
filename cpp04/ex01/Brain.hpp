#ifndef BRAIN_HH
#define BRAIN_HH

#include <iostream>

class Brain
{
        private:
                std::string ideas[100];
	public:
        Brain();
        Brain(const Brain &source);
        Brain &operator = (const Brain &rhs);
        ~Brain();

        void show() const;
};

#endif
