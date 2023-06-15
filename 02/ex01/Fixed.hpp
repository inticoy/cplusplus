/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 22:49:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/15 15:20:40 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
  Fixed();                           // default constructor
  Fixed(const int value);            // const int constructor
  Fixed(const float value);          // const float constructor
  Fixed(const Fixed& f);             // copy constructor
  ~Fixed();                          // destructor
  Fixed& operator=(const Fixed& f);  // overload copy assignment operator

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
