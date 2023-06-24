/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:14:30 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/24 14:37:52 by gyoon            ###   ########.fr       */
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

  void set_is_guard(bool is_guard);
  const bool &get_is_guard() const;

private:
  bool is_guard_;
};

#endif
