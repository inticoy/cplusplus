/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 22:49:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/18 19:57:22 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
  static Fixed& min(Fixed& f1, Fixed& f2);
  static const Fixed& min(const Fixed& f1, const Fixed& f2);
  static Fixed& max(Fixed& f1, Fixed& f2);
  static const Fixed& max(const Fixed& f1, const Fixed& f2);

  Fixed();                           // default constructor
  Fixed(const int value);            // const int constructor
  Fixed(const float value);          // const float constructor
  Fixed(const Fixed& f);             // copy constructor
  ~Fixed();                          // destructor
  Fixed& operator=(const Fixed& f);  // overload copy assignment operator

  // overload comparison operators
  bool operator>(const Fixed& f) const;
  bool operator<(const Fixed& f) const;
  bool operator>=(const Fixed& f) const;
  bool operator<=(const Fixed& f) const;
  bool operator==(const Fixed& f) const;
  bool operator!=(const Fixed& f) const;

  // overload arithmetic operators
  Fixed operator+(const Fixed& f) const;
  Fixed operator-(const Fixed& f) const;
  Fixed operator*(const Fixed& f) const;
  Fixed operator/(const Fixed& f) const;

  // overload increment/decrement operators
  Fixed& operator++();     // ++f;
  Fixed& operator++(int);  // f++;
  Fixed& operator--();     // --f;
  Fixed& operator--(int);  // f--;

  float toFloat() const;
  int toInt() const;

  void setRawBits(int const raw);
  int getRawBits(void) const;

private:
  const static int kFractionalBit = 8;
  int value_;
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif
