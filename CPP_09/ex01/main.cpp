#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << RED << "Error! Please use an expression." << RESET << std::endl;
		std::cout << YELLOW << "Example: ./RPN \"7 7 * 7 -\"" << RESET << std::endl;
		return (1);
	}
	RPN::calculate(argv[1]);
	return (0);
}