/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:38:10 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/19 16:03:26 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap() : name_(""), hit_(10), energy_(10), attack_damage_(0) {
  std::cout << "ClapTrap with no name created.";
  std::cout << std::endl;
}
ClapTrap::ClapTrap(std::string name)
    : name_(name), hit_(10), energy_(10), attack_damage_(0) {
  std::cout << "ClapTrap " << name << " created." << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &ct) {
  name_ = ct.name_;
  hit_ = ct.hit_;
  energy_ = ct.energy_;
  attack_damage_ = ct.attack_damage_;
}
ClapTrap::~ClapTrap() {}
ClapTrap &ClapTrap::operator=(const ClapTrap &ct) {
  name_ = ct.name_;
  hit_ = ct.hit_;
  energy_ = ct.energy_;
  attack_damage_ = ct.attack_damage_;
  return *this;
}

void ClapTrap::attack(const std::string &target) {
  std::cout << "ClapTrap " << (name_.empty() ? "no name" : name_) << " ";
  std::cout << "attacks " << target << ", ";
  std::cout << "causing " << attack_damage_ << " ";
  std::cout << "points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount) {
  hit_ -= amount;
  std::cout << "ClapTrap " << (name_.empty() ? "no name" : name_) << " ";
  std::cout << "take " << amount << " of damage, ";
  std::cout << "now health is " << hit_ << ".";
  std::cout << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount) {
  hit_ += amount;
  std::cout << "ClapTrap " << (name_.empty() ? "no name" : name_) << " ";
  std::cout << "is repaired " << amount << ", ";
  std::cout << "now health is " << hit_ << ".";
  std::cout << std::endl;
}