/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:25:30 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/23 21:25:13 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap() {
  std::cout << "FragTrap with no name created." << std::endl;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  set_hit(100);
  set_energy(100);
  set_attack_damage(30);
  std::cout << "FragTrap " << get_name_for_display() << " created.\n";
}
FragTrap::FragTrap(const FragTrap &ft) : ClapTrap(ft.get_name()) {
  set_hit(ft.get_hit());
  set_energy(ft.get_energy());
  set_attack_damage(ft.get_attack_damage());
  std::cout << "FragTrap " << get_name_for_display() << " created.\n";
}
FragTrap::~FragTrap() {
  std::cout << "FragTrap " << get_name_for_display() << " destroyed.\n";
}
FragTrap &FragTrap::operator=(const FragTrap &ft) {
  set_name(ft.get_name());
  set_hit(ft.get_hit());
  set_energy(ft.get_energy());
  set_attack_damage(ft.get_attack_damage());
  return *this;
}

void FragTrap::highFivesGuys() {
  std::cout << "FragTrap " << get_name_for_display() << " "
            << "wants to do a high five with you.\n";
}