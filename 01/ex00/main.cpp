/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:36:05 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/08 17:03:47 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Zombie.hpp"

int main() {
  std::cout << "[newZombie] Allocate Zombie Dynamically." << std::endl;
  Zombie *zombie = newZombie("Heap");
  zombie->announce();
  delete zombie;
  std::cout << std::endl;
  std::cout << "[randomChump] Using zombie on the stack." << std::endl;
  randomChump("Stack");
  return 0;
}
