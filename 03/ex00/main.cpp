/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 21:39:21 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/26 15:21:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"

int main()
{
    {
        std::cout << "TEST 1" << std::endl;
        ClapTrap clapTrap;
        clapTrap.attack("gyoon");
        clapTrap.takeDamage(4);
        clapTrap.beRepaired(9);
    }
    std::cout << std::endl;
    {
        std::cout << "TEST 2" << std::endl;
        ClapTrap clapTrap2("inticoy");
        clapTrap2.attack("0");
        clapTrap2.attack("1");
        clapTrap2.attack("2");
        clapTrap2.attack("3");
        clapTrap2.attack("4");
        clapTrap2.attack("5");
        clapTrap2.attack("6");
        clapTrap2.attack("7");
        clapTrap2.attack("8");
        clapTrap2.attack("9");
        clapTrap2.takeDamage(10);
        clapTrap2.beRepaired(8);
        clapTrap2.attack("gyoon");
    }
    return 0;
}