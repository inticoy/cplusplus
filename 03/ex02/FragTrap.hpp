/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:04:52 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/26 15:17:37 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FROGTRAP_HPP
#define FROGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
  public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap &fragTrap);
    ~FragTrap();
    FragTrap &operator=(const FragTrap &fragTrap);

    void highFivesGuys();
};

#endif
