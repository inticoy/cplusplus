/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:36:05 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/14 21:53:33 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Zombie.hpp"

int main() {
  std::cout << "[zombieHorde] Allocate 10 zombies in a single allocation.";
  std::cout << std::endl;
  Zombie *zombie = zombieHorde(10, "zombie");
  for (int i = 0; i < 10; i++) {
    zombie[i].announce();
  }
  delete[] zombie;
  return 0;
}
