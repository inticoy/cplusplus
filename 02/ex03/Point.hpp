/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:32:56 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/17 16:41:29 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
public:
  Point();                              // default constructor
  Point(const float x, const float y);  // two const floating-point constructor
  Point(const Point& p);                // copy constructor
  ~Point();                             // destructor
  Point& operator=(const Point& p);     // overload copy assignment operator

private:
  const Fixed x_;
  const Fixed y_;
};

#endif
