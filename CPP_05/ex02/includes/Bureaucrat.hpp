#pragma once

# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(void);									//Default constructor
		Bureaucrat(const std::string name, int grade);		//Constructor
		Bureaucrat(const Bureaucrat &copy);					//Copy constructor
		Bureaucrat &operator=(const Bureaucrat &copy);		//Copy assignment operator
		~Bureaucrat(void);									//Destructor

		//Member Functions
		const std::string	getName() const;
		int					getGrade() const;
		void				gradeIncrement();
		void				gradeDecrement();
		void				signForm(AForm &form);
		void				executeForm(AForm const & form);

		//Exceptions
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bur);