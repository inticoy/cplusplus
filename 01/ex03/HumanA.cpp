/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:09:37 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/17 13:55:20 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon)
    : name_(name), weapon_(weapon) {
  std::cout << "HumanA " << name_ << " with weapon created." << std::endl;
}
HumanA::~HumanA() {
  std::cout << "HumanA " << name_ << " destroyed." << std::endl;
}

void HumanA::attack() {
  std::cout << name_ << " attacks with his/her " << weapon_.get_type();
  std::cout << std::endl;
}