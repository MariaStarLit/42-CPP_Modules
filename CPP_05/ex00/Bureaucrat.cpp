#include "Bureaucrat.hpp"

//Constructores & Destructores
Bureaucrat::Bureaucrat() : _name("Nobody"), _grade(149)
{
	std::cout << CYAN << this->_name << " bureaucrat default constructor" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << CYAN << this->_name << " bureaucrat constructor" << RESET << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
	std::cout << CYAN << this->_name << " bureaucrat copy constructor" << RESET << std::endl;
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::cout << CYAN << this->_name << " bureaucrat copy assignment operator" << RESET << std::endl;
	std::string &temp = const_cast<std::string&>(_name);
	temp = copy.getName();
	this->_grade = copy._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << CYAN << this->_name << " bureaucrat destructor" << RESET << std::endl;
}

//Member functions
std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::gradeIncrement()
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::gradeDecrement()
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

//Exceptions
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("\033[0;31m Grade Too Low! \033[0m");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("\033[0;31m Grade Too High! \033[0m");
}

//Other functions
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bur)
{
	out << GREEN << bur.getName() << ", bureaucrat grade " << bur.getGrade() << "." << RESET;
	return (out);
}