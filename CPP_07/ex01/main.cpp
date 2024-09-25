#include "iter.hpp"

int main(void)
{
	int bunch[] = {1, 2, 3, 4};
	char alf[] = {'a', 'b', 'c', 'd'};

	std::cout << CYAN << "Print: " << RESET;
	iter(bunch, 4, print<int>);
	std::cout << std::endl;

	std::cout  << GREEN << "++ Adding 4 ++" << RESET << std::endl;
	iter(bunch, 4, add<int>);

	std::cout << CYAN << "Print: " << RESET;
	iter(bunch, 4, print<int>);
	std::cout << std::endl << std::endl;

	std::cout << CYAN << "Print: " << RESET;
	iter(alf, 4, print<char>);
	std::cout << std::endl;

	std::cout  << GREEN << "++ Adding 4 ++" << RESET << std::endl;
	iter(alf, 4, add<char>);

	std::cout << CYAN << "Print: " << RESET;
	iter(alf, 4, print<char>);
	std::cout << std::endl;
	return 0;
}