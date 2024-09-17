#pragma once

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern(void);							//Default constructor
		Intern(const Intern &copy);				//Copy constructor
		Intern &operator=(const Intern &copy);	//Copy assignment operator
		~Intern(void);							//Destructor

		//Member Functions
		AForm	*makeForm(std::string fname, std::string target);

		//Exceptions
		class FormNotFoundException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};