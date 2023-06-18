/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:32:56 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/18 20:27:59 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
public:
  static bool is_on_a_line(const Point a, const Point b, const Point c);

  Point();                              // default constructor
  Point(const float x, const float y);  // two const floating-point constructor
  Point(const Point& p);                // copy constructor
  ~Point();                             // destructor
  Point& operator=(const Point& p);     // overload copy assignment operator

  Point(const float x, const float y, const float z);
  const Point operator-(const Point& p) const;

  const Fixed& get_x() const;
  const Fixed& get_y() const;

private:
  const Fixed x_;
  const Fixed y_;

  const Fixed z_;
};

bool has_same_sign(const Fixed a, const Fixed b, const Fixed c);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
