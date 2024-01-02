#include "Serializer.hpp"

int main()
{
	Data		*ptr;
	Data		*new_ptr;
	uintptr_t	raw;

	ptr = new Data;
	ptr->value= 16;
	ptr->type = 'A';
	
	raw = Serializer::serialize (ptr);
	new_ptr = Serializer::deserialize(raw);
	std::cout << "Ptr value: " << ptr->value << std::endl;
	std::cout << "New_ptr value: " << new_ptr->value << std::endl;
	std::cout << "Ptr type: " << ptr->type << std::endl;
	std::cout << "New_ptr type: " << new_ptr->type << std::endl;
	delete ptr;
}
