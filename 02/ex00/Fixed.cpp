/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 22:49:30 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/15 15:00:32 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed() : value_(0) {
  std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed& f) {
  std::cout << "Copy constructor called" << std::endl;
  value_ = f.getRawBits();  // *this = f;
}
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }
Fixed& Fixed::operator=(const Fixed& f) {
  std::cout << "Copy assignment operator called" << std::endl;
  value_ = f.getRawBits();
  return *this;
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  value_ = raw;
}
int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return value_;
}
