#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_execute_grade;

	public:
		AForm(void);																	//Default constructor
		AForm(const std::string name, const int sign_grade, const int execute_grade);	//Constructor
		AForm(const AForm &copy);														//Copy constructor
		AForm &operator=(const AForm &copy);											//Copy assignment operator
		virtual ~AForm(void);																	//Destructor

		//Member Functions
		const std::string	getName() const;
		bool				getSigned() const;
		int					getGradeToSing() const;
		int					getGradeToExecute() const;
		void				beSigned(Bureaucrat &bur);
		virtual void		execute(const Bureaucrat& executor) const = 0;

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

std::ostream &operator<<(std::ostream &out, const AForm &bur);