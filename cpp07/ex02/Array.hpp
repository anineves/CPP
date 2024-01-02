#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <time.h>
#include <stdlib.h> 
template<typename T>
class Array
{
	private:
		T*				arr;
		unsigned int	len;
	public:
		Array();
		Array(unsigned int len);
		Array(Array const &source);
		Array &operator=(Array const &rhs);
		~Array();

		T& operator[]( unsigned int i ) const;
		unsigned int	size();
	
	class OutOfBoundsException: public std::exception
	{
		virtual const char* what() const throw()
		{
			return "The index value doesn't belong to the range.";
		}
	};
};

template<typename T>
Array<T>::Array(): arr(new T[0]), len(0)
{
}

template<typename T>
Array<T>::Array(unsigned int n) : arr(new T[n]), len(n)
{
	if (n < 0)
		throw Array<T>::OutOfBoundsException();
}

template<typename T>
Array<T>::Array(Array<T> const &source): arr(new T[source.len]), len(source.len)
{
	for (unsigned int i=0; i < source.len; i++)
	{
		arr[i] = source.arr[i];
	}
}

template<typename T>
Array<T> &Array<T>::operator=(Array<T> const &rhs)
{
	if (this != &rhs)
	{
		delete [] arr;
		arr = new T[rhs.len];
		len = rhs.len;
		for (unsigned int i=0; i < rhs.len; i++)
		{
			arr[i] = rhs.arr[i];
		}
		
	}
	return (*this);
}

template<typename T>
Array<T>::~Array()
{
	delete [] arr;
}

template<typename T>
T& Array<T>::operator[]( unsigned int index ) const
{
	if (index >= len)
		throw Array<T>::OutOfBoundsException();
	return(arr[index]);
}

template<typename T>
unsigned int	Array<T>::size()
{
	return (len);
}

#endif
