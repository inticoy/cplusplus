/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FrogTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:25:30 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/19 17:27:09 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FrogTrap.hpp"

FrogTrap::FrogTrap() {
  std::cout << "FrogTrap with no name created." << std::endl;
}
FrogTrap::FrogTrap(std::string name) {}
FrogTrap::FrogTrap(const FrogTrap &ft) {}
FrogTrap::~FrogTrap() {}
FrogTrap &FrogTrap::operator=(const FrogTrap &ft) {}