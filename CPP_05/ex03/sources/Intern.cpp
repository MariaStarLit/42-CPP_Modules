#include "Intern.hpp"

//Constructores & Destructor 
Intern::Intern()
{
	std::cout << YELLOW << "Intern default constructor" << RESET << std::endl;
}

Intern::Intern(const Intern &copy)
{
	std::cout << YELLOW << "Intern copy constructor" << RESET << std::endl;
	*this = copy;
}

Intern &Intern::operator=(const Intern &copy)
{
	std::cout << YELLOW << "Intern copy assignment operator" << RESET << std::endl;
	(void)copy;
	return (*this);
}

Intern::~Intern()
{
	std::cout << YELLOW << "Intern destructor" << RESET << std::endl;
}

//Member Functions
AForm	*Intern::makeForm(std::string fname, std::string target)
{
	std::string form_names[3] = {"ShrubberyCreationForm","RobotomyRequestForm","PresidentialPardonForm"};
	int			index = 3;

	for(int i = 0; i < 3; i++)
	{
		if (fname == form_names[i])
		{
			std::cout << YELLOW << "Intern creates " << fname << RESET << std::endl;
			index = i;
		}
	}
	try 
	{
		switch (index)
		{
			case 0:
				return (new ShrubberyCreationForm(target));
			case 1:
				return (new RobotomyRequestForm(target));
			case 2:
				return (new PresidentialPardonForm(target));
			default:
				throw Intern::FormNotFoundException();
		}
	}
	catch (const std::exception &exp) 
	{
		std::cout << YELLOW << "Exception: " << RESET << exp.what() << std::endl;
	}
	return (NULL);
}

//Exceptions
const char* Intern::FormNotFoundException::what() const throw()
{
	return "\033[0;31m Form not found \033[0m";
}