/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:14:30 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/19 16:21:39 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
  ScavTrap();
  ScavTrap(std::string name);
  ScavTrap(const ScavTrap &st);
  ~ScavTrap();
  ScavTrap &operator=(const ScavTrap &st);

  void attack(const std::string &target);
  void guardGate();

private:
  bool is_guard_;
};

#endif
