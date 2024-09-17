#include "ShrubberyCreationForm.hpp"

//Constructores & Destructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Unknown")
{
	std::cout << CYAN << "Shrubbery form default constructor" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << CYAN << "Shrubbery form constructor" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm("ShrubberyCreationForm", 145, 137), _target(copy._target)
{
	std::cout << CYAN << "Shrubbery copy form constructor" << RESET << std::endl;
	*this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	std::cout << CYAN << "Shrubbery copy form assignment operator" << RESET << std::endl;
	_target = copy._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << CYAN << "Shrubbery form destructor" << RESET << std::endl;
}

//Member Functions
const std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (!getSigned())
		throw ShrubberyCreationForm::NotSignedException();
	if (executor.getGrade() <= this->getGradeToExecute())
	{
		std::string filename = this->_target + "_shrubbery";
		std::ofstream file(filename.c_str());
		if (!file.is_open())
		{
			std::cout << RED << "Error! Opening file." << RESET << std::endl;
			return ;
		}
		file << "        ___                  ___                  ___          " << std::endl;
		file << "     /~~   ~~\\            /~~   ~~\\            /~~   ~~\\       " << std::endl;
		file << "  /~~         ~~\\      /~~         ~~\\      /~~         ~~\\    " << std::endl;
		file << " {               }    {               }    {               }   " << std::endl;
		file << "  \\  _       _  /      \\  _       _  /      \\  _       _  /    " << std::endl;
		file << "       \\\\ //  -        _    \\\\ //                \\\\ //         " << std::endl;
		file << "    _   | | _-           -   | |    _        _ -  | |   -      " << std::endl;
		file << "     -  | |    _        _    | |  -_            - | | _        " << std::endl;
		file << "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << std::endl;
		file.close();
	}
	else
		throw AForm::GradeTooLowException();
}

const char* ShrubberyCreationForm::NotSignedException::what() const throw()
{
	return "\033[0;31m Form not signed \033[0m";
}