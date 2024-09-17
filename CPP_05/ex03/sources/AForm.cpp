# include "AForm.hpp"

//Constructores & Destructores
AForm::AForm() : _name("Test"), _signed(0), _sign_grade(150), _execute_grade(150)
{
	std::cout << BLUE << this->_name << " AForm default constructor" << RESET << std::endl;
}

AForm::AForm(const std::string name, const int sign_grade, const int execute_grade) : _name(name), _signed(0), _sign_grade(sign_grade), _execute_grade(execute_grade)
{
	std::cout << BLUE << name << " AForm constructor" << RESET << std::endl;
	if (sign_grade < 1 || execute_grade < 1)
		throw AForm::GradeTooHighException();
	else if (sign_grade > 150 || execute_grade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _signed(0), _sign_grade(copy._sign_grade), _execute_grade(copy._execute_grade)
{
	std::cout << BLUE << this->_name << " AForm copy constructor" << RESET << std::endl;
	*this = copy;
}

AForm &AForm::operator=(const AForm &copy)
{
	std::cout << BLUE << this->_name << " AForm copy assignment operator" << RESET << std::endl;
	std::string &name = const_cast<std::string&>(_name);
	name = copy._name;
	int &sign = const_cast<int&>(_sign_grade);
	sign = copy._sign_grade;
	int &execute = const_cast<int&>(_execute_grade);
	execute = copy._execute_grade;
	this->_signed = copy._signed;
	return (*this);
}

AForm::~AForm()
{
	std::cout << BLUE << this->_name << " AForm destructor" << RESET << std::endl;
}

//Member Functions
const std::string	AForm::getName() const
{return (this->_name);}

bool	AForm::getSigned() const
{return (this->_signed);}

int	AForm::getGradeToSing() const
{return (this->_sign_grade);}

int	AForm::getGradeToExecute() const
{return (this->_execute_grade);}

void	AForm::beSigned(Bureaucrat &bur)
{
	if (bur.getGrade() <= this->_sign_grade)
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}

//Exceptions
const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("\033[0;31m Grade Too Low! \033[0m");
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("\033[0;31m Grade Too High! \033[0m");
}

//Other functions
std::ostream &operator<<(std::ostream &out, const AForm &Aform)
{
	out << BLUE << "\nAForm " << Aform.getName() << ":" << RESET << std::endl;
	if (Aform.getSigned())
		out  << BLUE << "-> " << GREEN << "Singed" << RESET << std::endl;
	else
		out  << BLUE << "-> " << RED << "Not Singed" << RESET << std::endl;
	out  << BLUE << "-> " << RESET << Aform.getGradeToSing() << " grade required to sign it" << std::endl
	 << BLUE << "-> " << RESET << Aform.getGradeToExecute() << " grade required to execute it" << std::endl;
	return (out);
}