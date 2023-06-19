/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:14:21 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/19 21:12:15 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap() : ClapTrap(), is_guard_(false) {
  std::cout << "ScavTrap with no name created." << std::endl;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name), is_guard_(false) {
  std::cout << "ScavTrap " << name << " created." << std::endl;
  hit_ = 100;
  energy_ = 50;
  attack_damage_ = 20;
}
ScavTrap::ScavTrap(const ScavTrap &st) : ClapTrap(st.name_) {
  std::cout << "ScavTrap " << (st.name_.empty() ? "no name" : name_);
  std::cout << " created." << std::endl;
  hit_ = st.hit_;
  energy_ = st.energy_;
  attack_damage_ = st.attack_damage_;
  is_guard_ = st.is_guard_;
}
ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap " << (name_.empty() ? "no name" : name_);
  std::cout << " destroyed." << std::endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &st) {
  name_ = st.name_;
  hit_ = st.hit_;
  energy_ = st.energy_;
  attack_damage_ = st.attack_damage_;
  is_guard_ = st.is_guard_;
  return *this;
}

void ScavTrap::attack(const std::string &target) {
  std::cout << "ScavTrap " << (name_.empty() ? "no name" : name_) << " ";
  std::cout << "attacks " << target << ", ";
  std::cout << "causing " << attack_damage_ << " ";
  std::cout << "points of damage!" << std::endl;
}
void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << (name_.empty() ? "no name" : name_) << " ";
  std::cout << (is_guard_ ? "is in a" : "is not in a") << " Gate Keeper mode.";
  std::cout << std::endl;
}