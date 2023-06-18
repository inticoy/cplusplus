/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 22:49:01 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/18 20:27:35 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Point.hpp"

int main(void) {
  std::cout << bsp(Point(0.f, 0.f), Point(0.f, 6.f), Point(6.f, 0.f),
                   Point(2.99f, 3.f))
            << std::endl;
  return 0;
}