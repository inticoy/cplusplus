/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 22:49:30 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/16 15:27:23 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed& Fixed::min(Fixed& f1, Fixed& f2) {
  if (f1.getRawBits() <= f2.getRawBits()) {
    return f1;
  } else {
    return f2;
  }
}
const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2) {
  if (f1.getRawBits() <= f2.getRawBits()) {
    return f1;
  } else {
    return f2;
  }
}
Fixed& Fixed::max(Fixed& f1, Fixed& f2) {
  if (f1.getRawBits() >= f2.getRawBits()) {
    return f1;
  } else {
    return f2;
  }
}
const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2) {
  if (f1.getRawBits() >= f2.getRawBits()) {
    return f1;
  } else {
    return f2;
  }
}

Fixed::Fixed() : value_(0) {
  // std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int value) {
  // std::cout << "Int constructor called" << std::endl;

  int positive_value = value >= 0 ? value : -value;
  if (value >= 0) {
    value_ = (positive_value << kFractionalBit) & ~(1 << 31);
  } else {
    value_ = ~(positive_value << kFractionalBit) | (1 << 31);
  }
  // value_ = (sign_bit << 31) | ((int_bits << kFractionalBit) & ~(1 << 31));
}
Fixed::Fixed(const float value) {
  // std::cout << "Float constructor called" << std::endl;

  int sign_bit = value >= 0 ? 0 : 1;
  float v = value >= 0 ? value : -value;
  if (value >= 0) {
    value_ = static_cast<int>(roundf(v * 256.f)) & ~(1 << 31);
  } else {
    value_ = ~static_cast<int>(roundf(v * 256.f)) | (1 << 31);
  }
}
Fixed::Fixed(const Fixed& f) {
  // std::cout << "Copy constructor called" << std::endl;
  value_ = f.getRawBits();  // *this = f;
}
Fixed::~Fixed() {
  // std::cout << "Destructor called" << std::endl;
}
Fixed& Fixed::operator=(const Fixed& f) {
  // std::cout << "Copy assignment operator called" << std::endl;
  value_ = f.getRawBits();
  return *this;
}

bool Fixed::operator>(const Fixed& f) { return getRawBits() > f.getRawBits(); }
bool Fixed::operator<(const Fixed& f) { return !(*this >= f); }
bool Fixed::operator>=(const Fixed& f) { return *this > f || *this == f; }
bool Fixed::operator<=(const Fixed& f) { return *this < f || *this == f; }
bool Fixed::operator==(const Fixed& f) {
  return getRawBits() == f.getRawBits();
}
bool Fixed::operator!=(const Fixed& f) { return !(*this == f); }

Fixed Fixed::operator+(const Fixed& f) {
  Fixed result;
  result.setRawBits(value_ + f.getRawBits());
  return result;
}
Fixed Fixed::operator-(const Fixed& f) {
  Fixed result;
  result.setRawBits(value_ - f.getRawBits());
  return result;
}
Fixed Fixed::operator*(const Fixed& f) {
  Fixed result;
  result.setRawBits(value_ * f.getRawBits() / 256);
  return result;
}
Fixed Fixed::operator/(const Fixed& f) {
  Fixed result;
  result.setRawBits(value_ * 256 / f.getRawBits());
  return result;
}

Fixed& Fixed::operator++() {
  ++value_;
  return *this;
}
Fixed& Fixed::operator++(int) {
  ++value_;
  return *this;
}
Fixed& Fixed::operator--() {
  --value_;
  return *this;
}
Fixed& Fixed::operator--(int) {
  --value_;
  return *this;
}

float Fixed::toFloat() const {
  return value_ / 256.f;
  // int sign = value_ >> 31 ? -1 : 1;
  // float float_part = (value_ & ~(1 << 31)) / 256.f;
  // return sign * float_part;
}
int Fixed::toInt() const {
  ;
  return value_ / 256;
}

void Fixed::setRawBits(int const raw) {
  // std::cout << "setRawBits member function called" << std::endl;
  value_ = raw;
}
int Fixed::getRawBits(void) const {
  // std::cout << "getRawBits member function called" << std::endl;
  return value_;
}

std::ostream& operator<<(std::ostream& os, const Fixed& f) {
  os << f.toFloat();
  return os;
}
