/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:14:30 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/18 22:24:59 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : ClapTrap {
public:
  ScavTrap();
  ScavTrap(const ScavTrap &st);
  ~ScavTrap();
  ScavTrap &operator=(const ScavTrap &st);

private:
  /* data */
};

#endif
