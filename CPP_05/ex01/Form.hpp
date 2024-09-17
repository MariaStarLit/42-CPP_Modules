#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_execute_grade;

	public:
		Form(void);																		//Default constructor
		Form(const std::string name, const int sign_grade, const int execute_grade);	//Constructor
		Form(const Form &copy);															//Copy constructor
		Form &operator=(const Form &copy);												//Copy assignment operator
		~Form(void);																	//Destructor

		//Member Functions
		const std::string	getName() const;
		bool				getSigned() const;
		int					getGradeToSing() const;
		int					getGradeToExecute() const;
		void				beSigned(Bureaucrat &bur);

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

std::ostream &operator<<(std::ostream &out, const Form &bur);