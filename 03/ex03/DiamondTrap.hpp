/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:49:39 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/24 14:49:41 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <string>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
public:
  static const int kHit = FragTrap::kHit;
  static const int kEnergy = ScavTrap::kEnergy;
  static const int kAttackDamage = FragTrap::kAttackDamage;

  DiamondTrap();
  DiamondTrap(std::string name);
  DiamondTrap(const DiamondTrap &dt);
  ~DiamondTrap();
  DiamondTrap &operator=(const DiamondTrap &dt);

  void attack(const std::string &target);
  void whoAmI();
  const std::string get_name_for_display() const;

  void set_name(std::string name);
  const std::string &get_name() const;

private:
  std::string name_;
};

#endif
