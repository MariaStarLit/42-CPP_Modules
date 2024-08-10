/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:15:16 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/12 05:29:09 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	{
		std::cout << std::endl << PURPLE << "My loop tests" << RESET << std::endl << std::endl;

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
		std::cout << std::endl << PURPLE << "My copy tests" << RESET << std::endl << std::endl;
		
		Dog Lua;
		Lua.telepathy();
		
		Dog Nova(Lua);
		Dog Estrela = Lua;
		Nova.telepathy();
		Estrela.telepathy();
		
		Lua.changeIdea(0, "I'm a Dog");
		Lua.changeIdea(2, "Squirrel!");
		Lua.changeIdea(4, "Let's go chace the cat");
		
		Lua.telepathy();
		Nova.telepathy();
		Estrela.telepathy();
	}
	return (0);
}