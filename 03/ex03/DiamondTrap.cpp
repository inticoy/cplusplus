/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:33:36 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/23 14:36:36 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap() {}
DiamondTrap::DiamondTrap(std::string name) {}
DiamondTrap::DiamondTrap(const DiamondTrap &dt) {}
DiamondTrap::~DiamondTrap() {}
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &dt) {}

void DiamondTrap::whoAmI() {
  std::cout << "DiamondTrap name : " << name_ << std::endl;
  std::cout << "ClapTrap name : " << name_ << std::endl;
}