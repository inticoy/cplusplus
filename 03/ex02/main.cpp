/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 21:39:21 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/26 15:17:45 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    {
        FragTrap frag_trap;
        frag_trap.attack("gyoon");
        frag_trap.takeDamage(20);
        frag_trap.beRepaired(50);
        frag_trap.highFivesGuys();
    }

    std::cout << std::endl;
    {
        FragTrap frag_trap("frag");
        frag_trap.attack("gyoon");
        frag_trap.takeDamage(20);
        frag_trap.beRepaired(50);
    }
    return 0;
}