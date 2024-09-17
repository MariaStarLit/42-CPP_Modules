#include "Bureaucrat.hpp"

int main(void)
{
	{
		std::cout << std::endl << PURPLE << "<<<<<<<<<<<<<<<<<<<<<<<<<< My Tests >>>>>>>>>>>>>>>>>>>>>>>>>>" << RESET << std::endl << std::endl;
		try
		{
			//Bureaucrat Jake("Jake", 0);
			Bureaucrat Bob("Bob", 3);
			Bureaucrat Ulisses;

			std::cout << std::endl << Bob << std::endl;
			Bob.gradeIncrement();
			std::cout << Bob << std::endl;
			Bob.gradeIncrement();
			std::cout << Bob << std::endl;
			// Bob.gradeIncrement();
			// std::cout << Bob << std::endl;

			std::cout << Ulisses << std::endl;
			Ulisses.gradeDecrement();
			std::cout << Ulisses << std::endl;
			// Ulisses.gradeDecrement();
			// std::cout << Ulisses << std::endl;

			std::cout << std::endl << YELLOW << "Copy cat:" << RESET << std::endl;
			Bureaucrat copy_cat(Bob);
			std::cout << copy_cat << std::endl;
			copy_cat = Ulisses;
			std::cout << copy_cat << std::endl << std::endl;
		}
		catch  (const std::exception &exp)
		{
			std::cout << "Exception: " << exp.what() << std::endl;
		}
	}
	return (0);
}