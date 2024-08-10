/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 22:10:15 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/11 22:10:53 by mde-avel         ###   ########.fr       */
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

class WrongAnimal
{
	protected:
		std::string		type;

	public:
		WrongAnimal(void);									//Default constructor
		WrongAnimal(std::string Wronganimal_type);			//Constructor
		WrongAnimal(const WrongAnimal &copy);				//Copy constructor
		WrongAnimal &operator=(const WrongAnimal &copy);	//Copy assignment operator
		~WrongAnimal(void);									//Destructor

		//Member Functions
		void	makeSound(void) const;
		std::string		getType(void) const;
};