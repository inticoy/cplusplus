/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:29:11 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/25 16:42:45 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include <iostream>

Animal::Animal() : type("") {
  std::cout << "Animal Default Constructor called.\n";
}
Animal::Animal(const Animal &a) {
  type = a.type;
  std::cout << "Animal Copy Constructor called.\n";
}
Animal::~Animal() { std::cout << "Animal Destructor called.\n"; }
Animal &Animal::operator=(const Animal &a) {
  std::cout << "Animal Assignment Operator called.\n";
}

void Animal::setType(std::string type) { this->type = type; }
std::string &Animal::getType() { return type; }
