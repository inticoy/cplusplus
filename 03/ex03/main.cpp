/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 21:39:21 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/26 15:28:03 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    {
        DiamondTrap diamondTrap;
        diamondTrap.attack("gyoon");
        diamondTrap.ClapTrap::attack("gyoon");
        diamondTrap.takeDamage(4);
        diamondTrap.beRepaired(9);
        diamondTrap.guardGate();
        diamondTrap.highFivesGuys();
        diamondTrap.whoAmI();
    }
    std::cout << std::endl;
    {
        DiamondTrap diamondTrap("Dia");
        diamondTrap.attack("gyoon");
        diamondTrap.ClapTrap::attack("gyoon");
        diamondTrap.takeDamage(4);
        diamondTrap.beRepaired(9);
        diamondTrap.guardGate();
        diamondTrap.highFivesGuys();
        diamondTrap.whoAmI();
    }
    return 0;
}