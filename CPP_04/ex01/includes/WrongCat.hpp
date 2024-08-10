/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 22:08:27 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/11 22:13:45 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);								//Default constructor
		WrongCat(const WrongCat &copy);				//Copy constructor
		WrongCat &operator=(const WrongCat &copy);	//Copy assignment operator
		~WrongCat(void);							//Destructor

		//Member Functions
		void	makeSound(void) const;
};