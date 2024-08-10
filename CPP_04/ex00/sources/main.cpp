/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:15:16 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/12 02:09:18 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		
		delete i;
		delete j;
		delete meta;
	}
	{
		std::cout << std::endl << GREEN << "My Animals tests" << RESET << std::endl << std::endl;
		Animal rabbit("Rabbit");
		Dog dog;
		Cat cat;
		rabbit.makeSound();
		dog.makeSound();
		cat.makeSound();
		rabbit = dog;
		rabbit.makeSound();
	}
	{
		std::cout << std::endl << RED << "My Wrong Animals tests" << RESET << std::endl << std::endl;
		
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