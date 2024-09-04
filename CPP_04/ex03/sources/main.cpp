/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:15:16 by mde-avel          #+#    #+#             */
/*   Updated: 2024/09/03 18:50:09 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int main()
{
	{
		std::cout << GREEN << "<<<<<<<<<<<<<<<<<<<<<<< Mandatory tests >>>>>>>>>>>>>>>>>>>>>>\n" << RESET << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << GREEN << "\n\n<<<<<<<<<<<<<<<<<<<<<<<<<<< My tests >>>>>>>>>>>>>>>>>>>>>>>>>>\n" << RESET << std::endl;
		
		Character Hero("Hero");
		Character Demon("Demon");
		MateriaSource src;
		src.learnMateria(new Cure());
		src.learnMateria(new Ice());
		src.learnMateria(new Cure());
		src.learnMateria(new Ice());
		src.learnMateria(new Cure());
		std::cout << std::endl;
		
		MateriaSource src2(src);
		src2.learnMateria(new Cure());
		std::cout << std::endl;
		
		AMateria* m = new Ice();
		Hero.equip(m);
		Hero.use(0, Demon);
		Hero.use(0, Demon);
		Hero.use(-1, Demon);
		
		AMateria* tmp;
		tmp = src.createMateria("ice");
		Hero.equip(tmp);
		tmp = src.createMateria("ice");
		Hero.equip(tmp);
		tmp = src.createMateria("batata");
		Hero.equip(tmp);
		tmp = src.createMateria("cure");
		Hero.equip(tmp);
		tmp = src.createMateria("cure");
		Hero.equip(tmp);
		tmp = src.createMateria("cure");
		Hero.equip(tmp);
		tmp = src.createMateria("ice");
		Demon.equip(tmp);

		Hero.unequip(0);
		Hero.unequip(1);
		Hero.unequip(1);
		Hero.unequip(5);

		Character copy(Demon);
		copy = Hero;
		tmp = src.createMateria("cure");
		copy.equip(tmp);
		tmp = src.createMateria("cure");
		copy.equip(tmp);
		copy.unequip(1);

		std::cout << std::endl;
	}
}
