/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 22:49:01 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/17 16:30:29 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"

int main(void) {
  Fixed a(0);
  Fixed const b(Fixed(5.05f) * Fixed(2));

  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;

  std::cout << a << std::endl;
  std::cout << --a << std::endl;
  std::cout << a << std::endl;
  std::cout << a-- << std::endl;

  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::min(a, b) << std::endl;
  return 0;
}