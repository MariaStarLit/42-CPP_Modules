#include "Serializer.hpp"

int	main(void)
{
	Data		ptr = {42,'*'};
	//Data		aux = {65, 'A'};
	Data		*res;
	uintptr_t	raw;

	std::cout << CYAN << "<<<<<<<<<<<<<<<<<<<<<<<< My test >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl << std::endl;
	
	raw = Serializer::serialize(&ptr);
	res = Serializer::deserialize(raw);
	if (&ptr == res)
		std::cout << GREEN << "Data is equal." << std::endl;
	else
		std::cout << RED << "Data is different!" << std::endl;

	// std::cout << std::endl << CYAN << "<<<<<<<<<<<<<<<<<<< How danamic cast works >>>>>>>>>>>>>>>>>>>" << RESET << std::endl << std::endl;

	// std::cout << raw << std::endl << std::endl;
	
	// std::cout << *reinterpret_cast<int *>(&ptr) << std::endl;
	// std::cout << reinterpret_cast<uintptr_t *>(&ptr) << std::endl;
	// std::cout << &(ptr) << std::endl;
	// std::cout << *reinterpret_cast<int *>(res) << std::endl;
	// std::cout << reinterpret_cast<uintptr_t *>(res) << std::endl;

	// std::cout << &(res) << std::endl;
	return (0);
}