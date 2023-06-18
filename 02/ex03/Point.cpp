/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:32:59 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/18 20:19:46 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool Point::is_on_a_line(const Point a, const Point b, const Point c) {
  const Point v_ab = b - a;
  const Point v_ac = c - a;
  if ((v_ab.x_ * v_ac.y_ - v_ab.y_ * v_ac.x_) == Fixed(0)) {
    return true;
  } else {
    return false;
  }
}

Point::Point() : x_(0), y_(0) {}
Point::Point(const float x, const float y) : x_(x), y_(y), z_(0) {}
Point::Point(const Point& p) : x_(p.x_), y_(p.y_) {}
Point::~Point() {}
Point& Point::operator=(const Point& p) { return *this; }  // can be done?

Point::Point(const float x, const float y, const float z)
    : x_(x), y_(y), z_(z) {}

const Point Point::operator-(const Point& p) const {
  Fixed x = x_ - p.x_;
  Fixed y = y_ - p.y_;
  Fixed z = z_ - p.z_;
  return Point(x.toFloat(), y.toFloat(), z.toFloat());
}

const Fixed& Point::get_x() const { return x_; }
const Fixed& Point::get_y() const { return y_; }
