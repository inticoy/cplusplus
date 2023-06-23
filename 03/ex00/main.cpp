/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 21:39:21 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/23 16:22:21 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"

int main() {
  {
    ClapTrap clap_trap;
    clap_trap.attack("gyoon");
    clap_trap.takeDamage(4);
    clap_trap.beRepaired(9);
  }

  std::cout << std::endl;

  {
    ClapTrap clap_trap2("inticoy");
    clap_trap2.attack("gyoon");
    clap_trap2.takeDamage(5);
    clap_trap2.beRepaired(8);
  }
  return 0;
}