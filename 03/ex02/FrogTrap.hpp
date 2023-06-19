/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FrogTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:04:52 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/19 17:28:54 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FROGTRAP_HPP
#define FROGTRAP_HPP

#include "ClapTrap.hpp"

class FrogTrap : public ClapTrap {
public:
  FrogTrap();
  FrogTrap(std::string name);
  FrogTrap(const FrogTrap &ft);
  ~FrogTrap();
  FrogTrap &operator=(const FrogTrap &ft);

  void highFivesGuys();

private:
};

#endif
