#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << RED << "Error! Please input a value." << RESET << std::endl;
		std::cout << YELLOW << "Example: ./convert [value]" << RESET << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}