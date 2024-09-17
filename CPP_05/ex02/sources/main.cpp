#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	{
		std::cout << GREEN << "<<<<<<<<<<<<<<<<<<<<<<<<<< My Tests >>>>>>>>>>>>>>>>>>>>>>>>>>" << RESET << std::endl << std::endl;
		try
		{
			ShrubberyCreationForm	straberry("forest");
			RobotomyRequestForm		robot("chair");
			PresidentialPardonForm	president("Carl");
			Bureaucrat				carl("Carl", 6);
			//Bureaucrat				bob("Bob", 151);
			//Bureaucrat				kevin("Kevin", 0);
			//AForm					a("A", 120, 90);
		
			std::cout << straberry << std::endl;
			std::cout << robot << std::endl;
			std::cout << president << std::endl;
			std::cout << carl << std::endl;
			//std::cout << bob << std::endl;

			carl.executeForm(straberry);
			carl.executeForm(robot);
			carl.executeForm(president);

			std::cout << std::endl;
			carl.signForm(straberry);
			carl.signForm(robot);
			carl.signForm(president);
			
			std::cout << std::endl;
			carl.executeForm(straberry);

			std::cout << std::endl;
			carl.executeForm(robot);
			carl.executeForm(robot);
			carl.executeForm(robot);
			carl.executeForm(robot);

			std::cout << std::endl;
			carl.executeForm(president);
			carl.gradeIncrement();
			std::cout << carl << std::endl;
			carl.executeForm(president);

			std::cout << straberry << std::endl;
			std::cout << robot << std::endl;
			std::cout << president << std::endl;
		}
		catch  (const std::exception &exp)
		{
			std::cout << "Exception: " << exp.what() << std::endl;
		}
	}
}