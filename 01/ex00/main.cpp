/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:36:05 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/13 17:40:19 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Zombie.hpp"

int main() {
  std::cout << "[newZombie] Allocate Zombie Dynamically." << std::endl;
  Zombie *zombie = newZombie("Heap");  // Dynamic Allocation @ Heap
  zombie->announce();                  // access by pointer
  delete zombie;                       // dynamic allocation needs deallocation

  std::cout << std::endl;

  std::cout << "[randomChump] Using zombie on the stack." << std::endl;
  randomChump("Stack");  // Static Allocation @ Stack in randomChump

  return 0;
}
