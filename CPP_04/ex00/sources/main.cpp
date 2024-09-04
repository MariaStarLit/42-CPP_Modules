/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:15:16 by mde-avel          #+#    #+#             */
/*   Updated: 2024/09/02 20:37:58 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		std::cout << std::endl << GREEN << "<<<<<<<<<<<<<<<< Animals tests >>>>>>>>>>>>>>>>" << RESET << std::endl << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << std::endl;
		Animal Jerry("Rat");
		Dog Hector;
		Cat Tom;

		std::cout << std::endl << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		Tom.makeSound();
		Hector.makeSound();
		Jerry.makeSound();
		meta->makeSound();
		std::cout << std::endl;

		delete i;
		delete j;
		delete meta;
		std::cout << std::endl;
	}
	{
		std::cout << std::endl << RED << "<<<<<<<<<<<<< Wrong Animals tests >>>>>>>>>>>>>" << RESET << std::endl << std::endl;
		
		const WrongAnimal* WAnimal = new WrongAnimal();
		const WrongAnimal* WCat = new WrongCat();
		
		WCat->makeSound();
		WAnimal->makeSound();
		
		delete WCat;
		delete WAnimal;
		std::cout << std::endl;
		
		WrongCat WCat2;
		WCat2.makeSound();
	}
	return (0);
}