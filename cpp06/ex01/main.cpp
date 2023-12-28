#include "Serializer.hpp"

int main()
{
	Data		*ptr;
	Data		*new_ptr;
	uintptr_t	raw;

	ptr = new Data;
	ptr->value= 16;
	
	raw = Serializer::serialize (ptr);
	new_ptr = Serializer::deserialize(raw);
	std::cout << "Ptr: " << ptr->value << std::endl;
	std::cout << "New_ptr: " << new_ptr->value << std::endl;
	delete ptr;
}