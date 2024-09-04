/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:35:08 by mde-avel          #+#    #+#             */
/*   Updated: 2024/08/16 18:31:36 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class ICharacter;

class Ice : public AMateria
{
	public:
		Ice(void);							//Default constructor
		Ice(const Ice &copy);				//Copy constructor
		Ice &operator=(const Ice &copy);	//Copy assignment operator
		~Ice(void);							//Destructor

		//Member Functions
		AMateria* clone() const;
		void use(ICharacter& target);
};
