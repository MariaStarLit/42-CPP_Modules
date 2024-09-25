#include "Array.hpp"

int	main(void)
{
	try
	{
		const int	n_el = 5;
		Array<int>	array(n_el);

		std::cout << GREEN << "\nEmpty Array ---> " << RESET;
		for (size_t i = 0; i < n_el; i++)
			std::cout << array[i] << " ";
		std::cout << std::endl << CYAN << "Array Size: " << RESET << array.size() << std::endl;

		array[3] = 4;
		array[4] = 2;

		Array<int>	copyArray(array);
		std::cout << std::endl << GREEN << "Copy Array ----> " << RESET;
		for (size_t i = 0; i < n_el; i++)
			std::cout << copyArray[i] << " ";
		std::cout << std::endl << CYAN << "Array Size: " << RESET << copyArray.size() << std::endl;
		
		Array<int>	copyArray2 = array;
		copyArray2 = array;
		std::cout << std::endl << GREEN << "Copy Opreator -> " << RESET;
		for (size_t i = 0; i < n_el; i++)
			std::cout << copyArray2[i] << " ";
		std::cout << std::endl << CYAN << "Array Size: " << RESET << copyArray2.size() << std::endl << std::endl;

		// Exceptions
		//std::cout << CYAN << "Index -1: " << RESET << array[-1] << std::endl;
		std::cout << CYAN << "Index 10: " << RESET << array[10] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
