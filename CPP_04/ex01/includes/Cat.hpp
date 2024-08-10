/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:15:27 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/12 04:13:15 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*_brian;
	public:
		Cat(void);								//Default constructor
		Cat(const Cat &copy);					//Copy constructor
		Cat &operator=(const Cat &copy);		//Copy assignment operator
		~Cat(void);								//Destructor

		//Member Functions
		void	makeSound(void) const;
		void	telepathy(void) const;
		void	changeIdea(int i, std::string ideia);
};