#include "PresidentialPardonForm.hpp"

//Constructores & Destructor
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Unknown")
{
	std::cout << CYAN << "Presidential form default constructor" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << CYAN << "Presidential form default constructor" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm("PresidentialPardonForm", 25, 5), _target(copy._target)
{
	std::cout << CYAN << "Presidential copy form constructor" << RESET << std::endl;
	*this = copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	std::cout << CYAN << "Presidential copy form assignment operator" << RESET << std::endl;
	_target = copy._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << CYAN << "Presidential form destructor" << RESET << std::endl;
}

//Member Functions
const std::string	PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (!getSigned())
		throw PresidentialPardonForm::NotSignedException();
	if (executor.getGrade() <= this->getGradeToExecute())
		std::cout << CYAN << this->_target << GREEN << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
	else
		throw AForm::GradeTooLowException();
}

//Exceptions
const char* PresidentialPardonForm::NotSignedException::what() const throw()
{
	return "\033[0;31m Form not signed \033[0m";
}