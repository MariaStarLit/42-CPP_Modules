#include "easyfind.hpp"
#include <vector>

const char *NotFoundException::what() const throw()
{
	return "\033[0;31mElement not found! \033[0m";
}

int	main(void)
{
	std::vector<int>	cont;
	int					element;

	for(int i = 0; i < 20; i++)
	{
		cont.push_back(i + 1);
	}
	try
	{
		element = easyfind(cont, 42);
		std::cout << GREEN << "Element found: " << RESET << element << std::endl;
	}
	catch (const std:: exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		element = easyfind(cont, 20);
		std::cout << GREEN << "Element found: " << RESET << element << std::endl;
	}
	catch (const std:: exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}