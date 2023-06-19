/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:25:30 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/19 21:12:22 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap() {
  std::cout << "FragTrap with no name created." << std::endl;
}
FragTrap::FragTrap(std::string name) {
  std::cout << "FragTrap " << name << " created." << std::endl;
  hit_ = 100;
  energy_ = 100;
  attack_damage_ = 30;
}
FragTrap::FragTrap(const FragTrap &ft) {
  std::cout << "FragTrap " << (ft.name_.empty() ? "no name" : name_);
  std::cout << " created." << std::endl;
  hit_ = ft.hit_;
  energy_ = ft.energy_;
  attack_damage_ = ft.attack_damage_;
}
FragTrap::~FragTrap() {
  std::cout << "ScavTrap " << (name_.empty() ? "no name" : name_);
  std::cout << " destroyed." << std::endl;
}
FragTrap &FragTrap::operator=(const FragTrap &ft) {
  name_ = ft.name_;
  hit_ = ft.hit_;
  energy_ = ft.energy_;
  attack_damage_ = ft.attack_damage_;
  return *this;
}

void FragTrap::highFivesGuys() {
  std::cout << "FragTrap " << (name_.empty() ? "no name" : name_) << " ";
  std::cout << "wants to do a high five with you." << std::endl;
}