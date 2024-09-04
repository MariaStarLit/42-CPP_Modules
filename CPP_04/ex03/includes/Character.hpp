/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:13:54 by mde-avel          #+#    #+#             */
/*   Updated: 2024/09/03 18:41:13 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ICharacter.hpp"
# include "AMateria.hpp"

struct Droped
{
	AMateria*	materia;
	Droped*		next;
};

class Character : public ICharacter
{
	private:
		std::string		_name;
		AMateria		*_materia[4];
		Droped			*_drop;

	public:
		Character(void);								//Default constructor
		Character(const std::string &name);				//Constructor
		Character(const Character &copy);				//Copy constructor
		Character &operator=(const Character &copy);	//Copy assignment operator
		~Character(void);								//Destructor

		//Member functions
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		bool isArrFull(AMateria **arr_m);
};
