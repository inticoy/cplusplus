/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:25:30 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/26 15:17:36 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
    hit = 100;
    energy = 100;
    attackDamage = 30;
    std::cout << "FragTrap with no name created." << std::endl;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    hit = 100;
    energy = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << getNameForDisplay() << " created.\n";
}
FragTrap::FragTrap(const FragTrap &fragTrap) : ClapTrap(fragTrap.name)
{
    this->hit = fragTrap.hit;
    this->energy = fragTrap.energy;
    this->attackDamage = fragTrap.attackDamage;
    std::cout << "FragTrap " << getNameForDisplay() << " created.\n";
}
FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << getNameForDisplay() << " destroyed.\n";
}
FragTrap &FragTrap::operator=(const FragTrap &fragTrap)
{
    this->name = fragTrap.name;
    this->hit = fragTrap.hit;
    this->energy = fragTrap.energy;
    this->attackDamage = fragTrap.attackDamage;
    return *this;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << getNameForDisplay() << " "
              << "wants to do a high five with you.\n";
}