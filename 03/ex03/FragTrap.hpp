/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:04:52 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/24 14:47:26 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FROGTRAP_HPP
#define FROGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
  static const int kHit = 100;
  static const int kEnergy = 100;
  static const int kAttackDamage = 30;

  FragTrap();
  FragTrap(std::string name);
  FragTrap(const FragTrap &ft);
  ~FragTrap();
  FragTrap &operator=(const FragTrap &ft);

  void highFivesGuys();
};

#endif
