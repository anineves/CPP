#include "Serializer.hpp"

int main()
{
	Data		*ptr;
	Data		*new_ptr;
	uintptr_t	raw;

	ptr = new Data;
	ptr->value= 13;
	
	raw = Serializer::serialize (ptr);
	new_ptr = Serializer::deserialize(raw);
	std::cout << "Value of ptr: " << ptr->value << std::endl;
	std::cout << "Value of new_ptr: " << new_ptr->value << std::endl;
	delete ptr;
}