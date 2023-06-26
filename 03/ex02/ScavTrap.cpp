/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:14:21 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/26 15:12:47 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
    hit = 100;
    energy = 50;
    attackDamage = 20;
    std::cout << "ScavTrap with no name created.\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    hit = 100;
    energy = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << getNameForDisplay() << " created.\n";
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap(scavTrap.name)
{
    this->hit = scavTrap.hit;
    this->energy = scavTrap.energy;
    this->attackDamage = scavTrap.attackDamage;
    std::cout << "ScavTrap " << getNameForDisplay() << " created.\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << getNameForDisplay() << " destroyed.\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap)
{
    this->name = scavTrap.name;
    this->hit = scavTrap.hit;
    this->energy = scavTrap.energy;
    this->attackDamage = scavTrap.attackDamage;
    return *this;
}

void ScavTrap::attack(const std::string &target)
{
    if (hit > 0 && energy > 0)
    {
        --energy;
        std::cout << "ScavTrap " << getNameForDisplay() << " ";
        std::cout << "attacks " << target << ", ";
        std::cout << "causing " << attackDamage << " ";
        std::cout << "points of damage!\n";
    }
    else if (hit <= 0)
    {
        std::cout << "ScavTrap " << getNameForDisplay() << " ";
        std::cout << "cannot attack " << target << " because of hit point.\n";
    }
    else
    {
        std::cout << "ScavTrap " << getNameForDisplay() << " ";
        std::cout << "cannot attack " << target << " because of energy point.\n";
    }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << getNameForDisplay() << " ";
    std::cout << "is in a Gate Keeper mode.\n";
}
