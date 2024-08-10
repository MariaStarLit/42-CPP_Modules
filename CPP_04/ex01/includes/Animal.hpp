/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:15:35 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/12 05:04:18 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

// Colors
# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"

class Animal
{
	protected:
		std::string		type;

	public:
		Animal(void);								//Default constructor
		Animal(std::string animal_type);			//Constructor
		Animal(const Animal &copy);					//Copy constructor
		Animal &operator=(const Animal &copy);		//Copy assignment operator
		virtual ~Animal(void);						//Destructor

		//Member Functions
		virtual void	makeSound(void) const;
		std::string		getType(void) const;
		virtual void	telepathy(void) const;
		virtual void	changeIdea(int i, std::string ideia);
};