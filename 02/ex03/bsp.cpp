/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:40:05 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/18 20:26:17 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool has_same_sign(const Fixed a, const Fixed b, const Fixed c) {
  if (a == Fixed(0) || b == Fixed(0) || c == Fixed(0)) {
    return false;
  } else if (a > Fixed(0) && b > Fixed(0) && c > Fixed(0)) {
    return true;
  } else if (a < Fixed(0) && b < Fixed(0) && c < Fixed(0)) {
    return true;
  } else {
    return false;
  }
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  if (Point::is_on_a_line(a, b, c)) {
    return false;
  } else {
    const Point v_ap = point - a;
    const Point v_bp = point - b;
    const Point v_cp = point - c;
    const Point v_ab = b - a;
    const Point v_bc = c - b;
    const Point v_ca = a - c;
    const Fixed z_a = v_ap.get_x() * v_ab.get_y() - v_ap.get_y() * v_ab.get_x();
    const Fixed z_b = v_bp.get_x() * v_bc.get_y() - v_bp.get_y() * v_bc.get_x();
    const Fixed z_c = v_cp.get_x() * v_ca.get_y() - v_cp.get_y() * v_ca.get_x();
    if (has_same_sign(z_a, z_b, z_c)) {
      return true;
    } else {
      return false;
    }
  }
}