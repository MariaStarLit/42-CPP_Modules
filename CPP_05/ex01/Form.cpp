# include "Form.hpp"

//Constructores & Destructores
Form::Form() : _name("Test"), _signed(0), _sign_grade(150), _execute_grade(150)
{
	std::cout << PURPLE << this->_name << " form default constructor" << RESET << std::endl;
}

Form::Form(const std::string name, const int sign_grade, const int execute_grade) : _name(name), _signed(0), _sign_grade(sign_grade), _execute_grade(execute_grade)
{
	std::cout << PURPLE << name << " form constructor" << RESET << std::endl;
	if (sign_grade < 1 || execute_grade < 1)
		throw Form::GradeTooHighException();
	else if (sign_grade > 150 || execute_grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &copy) : _name(copy._name), _signed(0), _sign_grade(copy._sign_grade), _execute_grade(copy._execute_grade)
{
	std::cout << PURPLE << this->_name << " form copy constructor" << RESET << std::endl;
	*this = copy;
}

Form &Form::operator=(const Form &copy)
{
	std::cout << PURPLE << this->_name << " form copy assignment operator" << RESET << std::endl;
	std::string &name = const_cast<std::string&>(_name);
	name = copy._name;
	int &sign = const_cast<int&>(_sign_grade);
	sign = copy._sign_grade;
	int &execute = const_cast<int&>(_execute_grade);
	execute = copy._execute_grade;
	this->_signed = copy._signed;
	return (*this);
}

Form::~Form()
{
	std::cout << PURPLE << this->_name << " form destructor" << RESET << std::endl;
}

//Member Functions
const std::string	Form::getName() const
{return (this->_name);}

bool	Form::getSigned() const
{return (this->_signed);}

int	Form::getGradeToSing() const
{return (this->_sign_grade);}

int	Form::getGradeToExecute() const
{return (this->_execute_grade);}

void	Form::beSigned(Bureaucrat &bur)
{
	if (bur.getGrade() <= this->_sign_grade)
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

//Exceptions
const char	*Form::GradeTooLowException::what() const throw()
{
	return ("\033[0;31m Grade Too Low! \033[0m");
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("\033[0;31m Grade Too High! \033[0m");
}

//Other functions
std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << PURPLE << "\nForm " << form.getName() << ":" << RESET << std::endl;
	if (form.getSigned())
		out  << PURPLE << "-> " << GREEN << "is Signed" << RESET << std::endl;
	else
		out  << PURPLE << "-> " << RED << "is not Signed" << RESET << std::endl;
	out  << PURPLE << "-> " << RESET << form.getGradeToSing() << " grade required to sign it" << std::endl
	 << PURPLE << "-> " << RESET << form.getGradeToExecute() << " grade required to execute it" << std::endl;
	return (out);
}