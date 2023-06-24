/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:25:30 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/24 14:47:41 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap() {
  set_hit(kHit);
  set_energy(kEnergy);
  set_attack_damage(kAttackDamage);
  std::cout << "FragTrap with no name created." << std::endl;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  set_hit(kHit);
  set_energy(kEnergy);
  set_attack_damage(kAttackDamage);
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