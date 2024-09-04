/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:15:16 by mde-avel          #+#    #+#             */
/*   Updated: 2024/09/02 21:45:15 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	{
		std::cout << std::endl << PURPLE << "<<<<<<<<<<<<<<<< Given tests >>>>>>>>>>>>>>>>" << RESET << std::endl << std::endl;
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;
		delete i;
	}
	{
		std::cout << std::endl << PURPLE << "<<<<<<<<<<<<<<< My loop tests >>>>>>>>>>>>>>>" << RESET << std::endl << std::endl;

		Animal* arr[4]; 
		for (int i = 0; i < 4; i++)
		{
			if (i < 2)
				arr[i] = new Dog();
			else
				arr[i] = new Cat();
			arr[i]->makeSound();
		}
		for (int i = 0; i < 4; i++)
			delete arr[i];
	}
	{
		std::cout << std::endl << PURPLE << "<<<<<<<<<<<<<<< My copy tests >>>>>>>>>>>>>>>" << RESET << std::endl << std::endl;
		//Animal test;
		Dog Lua;
		Dog Nova(Lua);
		Dog Estrela;
		Estrela = Lua;
		
		std::cout << CYAN << "Lua " << RESET;
		Lua.telepathy();
		std::cout << CYAN << "Nova " << RESET;
		Nova.telepathy();
		std::cout << CYAN << "Estrela " << RESET;
		Estrela.telepathy();
		
		Lua.changeIdea(0, "I'm a Dog");
		Lua.changeIdea(2, "Squirrel!");
		Lua.changeIdea(4, "Let's go chace the cat");
		std::cout << YELLOW << "Lua ideias were changed!" << RESET << std::endl;
		
		std::cout << CYAN << "Lua " << RESET;
		Lua.telepathy();
		std::cout << CYAN << "Nova " << RESET;
		Nova.telepathy();
		std::cout << CYAN << "Estrela " << RESET;
		Estrela.telepathy();
	}
	return (0);
}