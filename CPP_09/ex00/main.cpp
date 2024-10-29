#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << RED << "Error: could not open file." << RESET << std::endl;
		std::cout << YELLOW << "Example: ./btc file_name" << RESET << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange trade;

		trade.extractFile(argv[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what();
		return (2);
	}
	return (0);
}