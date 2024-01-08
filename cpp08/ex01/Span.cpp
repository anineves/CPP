#include "Span.hpp"

Span::Span()
{

}

//reserve() – Requests that the vector capacity be at least enough to contain n elements.
Span::Span (unsigned int N)
{
    this->vect.reserve(N);
}

Span::Span(const Span &source)
{
    this->vect = source.vect;
}

Span& Span::operator= (const Span &rhs)
{
    if(this != &rhs)
    {
        this->vect = rhs.vect;
    }
    return *this;
}

Span::~Span()
{

}
//capacity() – Returns the size of the storage space currently allocated to the vector expressed as number of elements.

//push_back() – It push the elements into a vector from the back

void Span::addNumber (int n)
{
    if(vect.size() >= vect.capacity())
        throw Span::SpanFull();
    
    this->vect.push_back(n);
}

//insert() – It inserts new elements before the element at the specified position
//std::distance() Return value The number of increments needed to go from first to last.
void Span::addNumber2(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end)
{
    int range = std::distance(begin, end);
	if (range + this->vect.size() > this->vect.capacity() )
	{
		this->vect.insert(vect.end(), begin, begin + (this->vect.capacity() - this->vect.size()));
		throw Span::SpanFull();
	}
	else
		vect.insert(vect.end(), begin, end);
}
//begin() – Returns an iterator pointing to the first element in the vector

//end() – Returns an iterator pointing to the theoretical element that follows the last element in the vector
long int Span::shortestSpan()
{
    long int diff = Span::longestSpan();
	
    if (vect.size() <= 1)
		throw Span::FewElements();

	for (std::vector<int>::iterator ptr = vect.begin(); ptr < vect.end(); ptr++)
	{
		for (std::vector<int>::iterator ptr1 = vect.begin(); ptr1 < vect.end(); ptr1++)
		{
			if (ptr == ptr1)
				continue;
			if (std::abs((long)*ptr - (long)*ptr1) < diff)
					diff = std::abs((long)*ptr - (long)*ptr1);
		}
	}
	return (diff);
}


long int Span::longestSpan()
{
      if(this->vect.size() <= 1)
        throw FewElements();

    long  max;
    long  min;
    max = *std::max_element(vect.begin(), vect.end());
    min = *std::min_element(vect.begin(), vect.end());

    return ( std::abs(max-min));
}


void	Span::print()
{
	for (unsigned int i = 0; i < vect.size(); i++)
		std::cout << "Span " << i << " = " << vect[i] << std::endl;
	
}
