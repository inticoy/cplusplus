/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 21:39:21 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/26 15:06:02 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"

int main()
{
    {
        std::cout << "TEST 1" << std::endl;
        ClapTrap clap_trap;
        clap_trap.attack("gyoon");
        clap_trap.takeDamage(4);
        clap_trap.beRepaired(9);
    }
    std::cout << std::endl;
    {
        std::cout << "TEST 2" << std::endl;
        ClapTrap clap_trap2("inticoy");
        clap_trap2.attack("0");
        clap_trap2.attack("1");
        clap_trap2.attack("2");
        clap_trap2.attack("3");
        clap_trap2.attack("4");
        clap_trap2.attack("5");
        clap_trap2.attack("6");
        clap_trap2.attack("7");
        clap_trap2.attack("8");
        clap_trap2.attack("9");
        clap_trap2.takeDamage(10);
        clap_trap2.beRepaired(8);
        clap_trap2.attack("gyoon");
    }
    return 0;
}