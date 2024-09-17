#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << GREEN << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< My Tests >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << RESET << std::endl << std::endl;
	try
	{
		AForm		*robot;
		AForm		*president;
		AForm		*straberry;
		AForm		*fail;
		Intern		intern;
		Bureaucrat	max("Max", 26);
		//Bureaucrat	bob("Bob", 151);

		std::cout << std::endl;

		straberry = intern.makeForm("ShrubberyCreationForm", "form1");
		robot = intern.makeForm("RobotomyRequestForm", "form2");
		president = intern.makeForm("PresidentialPardonForm", "form3");

		std::cout << std::endl;
		fail = intern.makeForm("Banana", "form4");

		std::cout << std::endl;
		max.signForm(*straberry);
		max.executeForm(*straberry);

		std::cout << std::endl;
		max.signForm(*robot);
		max.executeForm(*robot);
		max.executeForm(*robot);
		max.executeForm(*robot);
		max.executeForm(*robot);

		std::cout << std::endl;
		max.signForm(*president);
		max.executeForm(*president);

		std::cout << *straberry << std::endl;
		std::cout << *robot << std::endl;
		std::cout << *president << std::endl;

		std::cout << std::endl;
		delete robot;
		delete president;
		delete straberry;
		delete fail;
	}
	catch  (const std::exception &exp)
	{
		std::cout << "Exception: " << exp.what() << std::endl;
	}
}