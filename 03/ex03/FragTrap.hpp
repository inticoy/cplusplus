/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:04:52 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/23 21:57:21 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FROGTRAP_HPP
#define FROGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
  FragTrap();
  FragTrap(std::string name);
  FragTrap(const FragTrap &ft);
  ~FragTrap();
  FragTrap &operator=(const FragTrap &ft);

  void highFivesGuys();
};

#endif
