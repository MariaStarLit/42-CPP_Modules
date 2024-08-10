/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:15:20 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/12 04:19:38 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*_brian;
	public:
		Dog(void);								//Default constructor
		Dog(const Dog &copy);					//Copy constructor
		Dog &operator=(const Dog &copy);		//Copy assignment operator
		~Dog(void);								//Destructor

		//Member Functions
		void	makeSound(void) const;
		void	telepathy(void) const;
		void	changeIdea(int i, std::string ideia);
};