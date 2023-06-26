/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:33:36 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/26 15:45:55 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(), name("")
{
    hit = kHit;
    energy = kEnergy;
    attackDamage = kAttackDamage;
    std::cout << "DiamondTrap with no name created." << std::endl;
}
DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), name(name)
{
    hit = kHit;
    energy = kEnergy;
    attackDamage = kAttackDamage;
    std::cout << "DiamondTrap " << getNameForDisplay() << " created.\n";
}
DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap)
{
    ClapTrap::name = diamondTrap.ClapTrap::name;
    name = diamondTrap.name;
    hit = diamondTrap.hit;
    energy = diamondTrap.energy;
    attackDamage = diamondTrap.attackDamage;
    std::cout << "DiamondTrap " << getNameForDisplay() << " created.\n";
}
DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << getNameForDisplay() << " destroyed.\n";
}
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap)
{
    ClapTrap::name = diamondTrap.ClapTrap::name;
    name = diamondTrap.name;
    hit = diamondTrap.hit;
    energy = diamondTrap.energy;
    attackDamage = diamondTrap.attackDamage;
    return *this;
}

void DiamondTrap::whoAmI()
{
    std::cout << "I want to introduce myself.\n";
    std::cout << "DiamondTrap name is " << getNameForDisplay() << "\n";
    std::cout << "ClapTrap name is " << ClapTrap::getNameForDisplay() << "\n";
}
const std::string DiamondTrap::getNameForDisplay() const
{
    return name.empty() ? "with no name" : "[" + name + "]";
}
