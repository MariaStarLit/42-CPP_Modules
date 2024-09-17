#pragma once

#include "AForm.hpp"
#include <stdlib.h>

class RobotomyRequestForm : public AForm
{
	private:
		std::string		_target;

	public:
		RobotomyRequestForm(void);											//Default constructor
		RobotomyRequestForm(const std::string target);						//Constructor
		RobotomyRequestForm(const RobotomyRequestForm &copy);				//Copy constructor
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);	//Copy assignment operator
		~RobotomyRequestForm(void);											//Destructor

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