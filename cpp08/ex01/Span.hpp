#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <list>
#include <exception>
#include <algorithm>
#include <vector>
#include <limits>


class Span
{
    private:
        std::vector<int> vect;
        Span(); 


    public:
        Span (unsigned int);
        Span (const Span &source);
        Span& operator= (const Span &rhs);
        ~Span ();

        void addNumber (int);
        void addNumber2 (const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end);
        long int longestSpan();
        long int shortestSpan();
        void print();

        class SpanFull : public std::exception
        {
            public:
			virtual const char* what() const throw()
			{
				return "Span is full.";
			}
        };

        class FewElements : public std::exception
        {
            public:
			virtual const char* what() const throw()
			{
				return "The Span must be elements";
			}
        };
};

#endif