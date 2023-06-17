/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:32:59 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/17 16:47:51 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x_(0), y_(0) {}
Point::Point(const float x, const float y) : x_(x), y_(y) {}
Point::Point(const Point& p) : x_(p.x_), y_(p.y_) {}
Point::~Point() {}
Point& Point::operator=(const Point& p) { return *this; }  // can be done?
