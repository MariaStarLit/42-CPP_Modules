#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string			_target;

	public:
		PresidentialPardonForm(void);											//Default constructor
		PresidentialPardonForm(const std::string target);						//Constructor
		PresidentialPardonForm(const PresidentialPardonForm &copy);				//Copy constructor
		PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);	//Copy assignment operator
		~PresidentialPardonForm(void);											//Destructor

		//Member Functions
		const std::string	getTarget() const;
		void				execute(const Bureaucrat& executor) const;

		//Exceptions
		class NotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};