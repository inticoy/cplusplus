/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:38:10 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/26 15:07:27 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap() : name(""), hit(10), energy(10), attackDamage(0)
{
    std::cout << "ClapTrap with no name created.\n";
}

ClapTrap::ClapTrap(std::string name) : name(name), hit(10), energy(10), attackDamage(0)
{
    std::cout << "ClapTrap " << getNameForDisplay() << " created.\n";
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
    this->name = clapTrap.name;
    this->hit = clapTrap.hit;
    this->energy = clapTrap.energy;
    this->attackDamage = clapTrap.attackDamage;
    std::cout << "ClapTrap " << getNameForDisplay() << " created.\n";
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << getNameForDisplay() << " destroyed.\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
    this->name = clapTrap.name;
    this->hit = clapTrap.hit;
    this->energy = clapTrap.energy;
    this->attackDamage = clapTrap.attackDamage;
    std::cout << "ClapTrap " << getNameForDisplay() << " assigned.\n";
    return *this;
}

void ClapTrap::attack(const std::string &target)
{
    if (hit > 0 && energy > 0)
    {
        --energy;
        std::cout << "ClapTrap " << getNameForDisplay() << " ";
        std::cout << "attacks " << target << ", ";
        std::cout << "causing " << this->attackDamage << " ";
        std::cout << "points of damage!\n";
    }
    else if (hit <= 0)
    {
        std::cout << "ClapTrap " << getNameForDisplay() << " ";
        std::cout << "cannot attack " << target << " because it has no hit point.\n";
    }
    else
    {
        std::cout << "ClapTrap " << getNameForDisplay() << " ";
        std::cout << "cannot attack " << target << " because it has no energy point.\n";
    }
}
void ClapTrap::takeDamage(unsigned int amount)
{
    hit -= amount;
    if (hit < 0)
    {
        hit = 0;
    }
    std::cout << "ClapTrap " << getNameForDisplay() << " ";
    std::cout << "take " << amount << " of damage, ";
    std::cout << "now health is " << hit << ".\n";
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (hit > 0 && energy > 0)
    {
        --energy;
        hit += amount;
        std::cout << "ClapTrap " << getNameForDisplay() << " ";
        std::cout << "is repaired " << amount << ", ";
        std::cout << "now health is " << hit << ".\n";
    }
    else if (hit <= 0)
    {
        std::cout << "ClapTrap " << getNameForDisplay() << " ";
        std::cout << "cannot be repaired because it has no hit point.\n";
    }
    else
    {
        std::cout << "ClapTrap " << getNameForDisplay() << " ";
        std::cout << "cannot be repaired because it has no energy point.\n";
    }
}
const std::string ClapTrap::getNameForDisplay() const
{
    return this->name.empty() ? "with no name" : "[" + name + "]";
}
