#include "RobotomyRequestForm.hpp"

//Constructores & Destructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Unknown")
{
	std::cout << CYAN << "Roboto form default constructor" << RESET << std::endl;
	srand(time(0));
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << CYAN << "Roboto form constructor" << RESET << std::endl;
	srand(time(0));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm("RobotomyRequestForm", 72, 45), _target(copy._target)
{
	std::cout << CYAN << "Roboto copy form constructor" << RESET << std::endl;
	*this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	std::cout << CYAN << "Roboto copy form assignment operator" << RESET << std::endl;
	srand(time(0));
	_target = copy._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << CYAN << "Roboto form destructor" << RESET << std::endl;
}

//Member Functions
const std::string	RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (!getSigned())
		throw RobotomyRequestForm::NotSignedException();
	if (executor.getGrade() <= this->getGradeToExecute())
	{
		std::cout << CYAN << "* ZZZZZZZRRRRRRTTTTT-ZZZRRRR-RRRZZZZZRTTT *" << RESET << std::endl;
		if (rand() % 2)
			std::cout << CYAN << this->_target << GREEN << " has been robotomized successfully" << RESET << std::endl;
		else
			std::cout << CYAN <<this->_target << RED << " robotomy failed" << RESET << std::endl;
	}
	else
		throw AForm::GradeTooLowException();
}

//Exceptions
const char* RobotomyRequestForm::NotSignedException::what() const throw()
{
	return "\033[0;31m Form not signed \033[0m";
}