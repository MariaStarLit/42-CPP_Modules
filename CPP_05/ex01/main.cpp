#include "Form.hpp"

int main()
{
	{
		std::cout << GREEN << "<<<<<<<<<<<<<<<<<<<<<<<<<< My Tests >>>>>>>>>>>>>>>>>>>>>>>>>>" << RESET << std::endl;
		try
		{
			Form		a("A", 70, 150);
			//Form		b("B", 0, 17);
			//Form		c("C", 10, 151);
			Bureaucrat	jonh("Jonh", 71);
			Bureaucrat	lucky("Lucky", 1);
		
			std::cout << a << std::endl;
			jonh.signForm(a);
			std::cout << a << std::endl;
			jonh.gradeIncrement();
			std::cout << jonh << std::endl;
			jonh.signForm(a);
			std::cout << a << std::endl;

			std::cout << lucky << std::endl;
			//lucky.gradeIncrement();
			//std::cout << lucky << std::endl;
		}
		catch  (const std::exception &exp)
		{
			std::cout << "Exception: " << exp.what() << std::endl;
		}
	}
}