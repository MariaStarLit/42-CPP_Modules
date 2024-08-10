/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:37:37 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/08 18:37:10 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a("Merlin");
	a.printStatus();
	ClapTrap b;
	b.printStatus();
	
	for (int i = 0; i < 6; i++)
		a.attack(b);
		
	a.takeDamage(12);
	a.takeDamage(5);
	a.attack(b);
	
	a.beRepaired(3);
	a.printStatus();
	
	ClapTrap c(a);
	c.printStatus();
	
	for (int i = 0; i < 4; i++)
		c.attack(b);
	c.beRepaired(2);
	
	return (0);
}