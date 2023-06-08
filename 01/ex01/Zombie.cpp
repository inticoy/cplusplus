/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:36:07 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/09 00:11:42 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie() : name_("") {
  std::cout << "Zombie created with no name." << std::endl;
}
Zombie::Zombie(std::string name) : name_(name) {
  std::cout << "Zombie " << name << " created." << std::endl;
}
Zombie::~Zombie() {
  std::cout << "Zombie " << name_ << " destroyed." << std::endl;
}

void Zombie::announce() {
  std::cout << name_ << ": ";
  std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name) { name_ = name; }
const std::string &Zombie::get_name() const { return name_; }