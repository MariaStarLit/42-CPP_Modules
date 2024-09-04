/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:37:56 by mde-avel          #+#    #+#             */
/*   Updated: 2024/08/16 18:31:43 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class ICharacter;

class Cure : public AMateria
{
	public:
		Cure(void);							//Default constructor
		Cure(const Cure &copy);				//Copy constructor
		Cure &operator=(const Cure &copy);	//Copy assignment operator
		~Cure(void);						//Destructor

		//Member Functions
		AMateria* clone() const;
		void use(ICharacter& target);
};
