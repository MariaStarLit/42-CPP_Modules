/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:15:35 by mde-avel          #+#    #+#             */
/*   Updated: 2024/09/02 21:55:38 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Character.hpp"

// Colors
# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"

class ICharacter;

class AMateria
{
	protected:
		std::string		_type;

	public:
		AMateria(void);								//Default constructor
		AMateria(std::string const &type);			//Constructor
		AMateria(const AMateria &copy);				//Copy constructor
		AMateria &operator=(const AMateria &copy);	//Copy assignment operator
		virtual ~AMateria(void);					//Destructor

		//Member Functions
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
