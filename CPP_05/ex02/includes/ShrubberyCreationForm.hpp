#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string		_target;

	public:
		ShrubberyCreationForm(void);											//Default constructor
		ShrubberyCreationForm(std::string target);								//Constructor
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);				//Copy constructor
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);	//Copy assignment operator
		~ShrubberyCreationForm(void);											//Destructor

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