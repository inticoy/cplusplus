/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 22:49:30 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/18 19:55:47 by gyoon            ###   ########.fr       */
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

Fixed::Fixed() : value_(0) {}
Fixed::Fixed(const int value) {
  value_ = value << kFractionalBit;
  if (value >= 0) {
    value_ &= ~(1 << 31);  // turn off most significant bit (postivive)
  } else {
    value_ |= 1 << 31;  // turn on most significant bit (negative)
  }
}
Fixed::Fixed(const float value) {
  value_ = static_cast<int>(roundf(value * 256.f));
  if (value >= 0) {
    value_ &= ~(1 << 31);  // turn off most significant bit (postivive)
  } else {
    value_ |= 1 << 31;  // turn on most significant bit (negative)
  }
}
Fixed::Fixed(const Fixed& f) {
  value_ = f.getRawBits();  // *this = f;
}
Fixed::~Fixed() {}
Fixed& Fixed::operator=(const Fixed& f) {
  value_ = f.getRawBits();
  return *this;
}

bool Fixed::operator>(const Fixed& f) const {
  return getRawBits() > f.getRawBits();
}
bool Fixed::operator<(const Fixed& f) const { return !(*this >= f); }
bool Fixed::operator>=(const Fixed& f) const { return *this > f || *this == f; }
bool Fixed::operator<=(const Fixed& f) const { return *this < f || *this == f; }
bool Fixed::operator==(const Fixed& f) const {
  return getRawBits() == f.getRawBits();
}
bool Fixed::operator!=(const Fixed& f) const { return !(*this == f); }

Fixed Fixed::operator+(const Fixed& f) const {
  Fixed result;
  result.setRawBits(value_ + f.getRawBits());
  return result;
}
Fixed Fixed::operator-(const Fixed& f) const {
  Fixed result;
  result.setRawBits(value_ - f.getRawBits());
  return result;
}
Fixed Fixed::operator*(const Fixed& f) const {
  Fixed result;
  result.setRawBits(value_ * f.getRawBits() / 256);
  return result;
}
Fixed Fixed::operator/(const Fixed& f) const {
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

float Fixed::toFloat() const { return (value_ / 256.f); }
int Fixed::toInt() const { return static_cast<int>(value_ / 256); }

void Fixed::setRawBits(int const raw) { value_ = raw; }
int Fixed::getRawBits(void) const { return value_; }

std::ostream& operator<<(std::ostream& os, const Fixed& f) {
  os << f.toFloat();
  return os;
}
