/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:14:30 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/25 15:18:31 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
  static const int kHit = 100;
  static const int kEnergy = 50;
  static const int kAttackDamage = 20;

  ScavTrap();
  ScavTrap(std::string name);
  ScavTrap(const ScavTrap &st);
  ~ScavTrap();
  ScavTrap &operator=(const ScavTrap &st);

  void attack(const std::string &target);
  void guardGate();
};

#endif
