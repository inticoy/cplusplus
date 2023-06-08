/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Color.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:10:31 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/08 14:51:50 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_HPP
#define COLOR_HPP

#include <string>

namespace color {
const std::string kRed = "\033[1;31m";
const std::string kYellow = "\033[1;33m";
const std::string kBlue = "\033[1;34m";
const std::string kEnd = "\033[1;0m";
}  // namespace color

#endif