/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 22:49:30 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/17 16:28:14 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed() : value_(0) {
  std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int value) {
  std::cout << "Int constructor called" << std::endl;

  value_ = value << kFractionalBit;
  if (value >= 0) {
    value_ &= ~(1 << 31);  // turn off most significant bit (postivive)
  } else {
    value_ |= 1 << 31;  // turn on most significant bit (negative)
  }
}
Fixed::Fixed(const float value) {
  std::cout << "Float constructor called" << std::endl;

  value_ = static_cast<int>(roundf(value * 256.f));
  if (value >= 0) {
    value_ &= ~(1 << 31);  // turn off most significant bit (postivive)
  } else {
    value_ |= 1 << 31;  // turn on most significant bit (negative)
  }
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

float Fixed::toFloat() const { return (value_ / 256.f); }
int Fixed::toInt() const { return static_cast<int>(value_ / 256); }

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  value_ = raw;
}
int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return value_;
}

std::ostream& operator<<(std::ostream& os, const Fixed& f) {
  os << f.toFloat();
  return os;
}
