/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 22:49:30 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/15 16:44:53 by gyoon            ###   ########.fr       */
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
  int sign_bit = value > 0 ? 0 : 1;
  int int_bits = value >= 0 ? value : -value;
  value_ = (sign_bit << 31) | (int_bits << kFractionalBit);
}
Fixed::Fixed(const float value) {
  std::cout << "Float constructor called" << std::endl;
  // int bits = static_cast<int>(roundf(value * 256.f));
  // value_ = (bits);
  int sign_bit = value >= 0 ? 0 : 1;
  float v = value >= 0 ? value : -value;
  int bits = static_cast<int>(roundf(v * 256.f));
  value_ = (sign_bit << 31) | (bits & ~(1 << 31));
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

float Fixed::toFloat() const {
  int sign = value_ >> 31 ? -1 : 1;
  float v = (value_ & ~(1 << 31)) / 256.f;
  float f_value = sign * v;
  // float f_value = value_ / 256.f;
  return f_value;
}
int Fixed::toInt() const {
  int sign = value_ >> 31 ? -1 : 1;
  int int_part = (value_ & ~(1 << 31)) >> kFractionalBit;
  int d_value = sign * int_part;
  return d_value;
}

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
