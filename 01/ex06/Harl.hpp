/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:13:56 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/15 00:34:34 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>

#define LVLS 5

namespace color {
const std::string kRed = "\033[1;31m";
const std::string kYellow = "\033[1;33m";
const std::string kBlue = "\033[1;34m";
const std::string kEnd = "\033[1;0m";
}  // namespace color

class Harl {
public:
  Harl();
  ~Harl();
  void complain(std::string level);
  void complain(const char *level);

private:
  enum { kDebug = 0, kInfo, kWarning, kError, kUndefined };
  const static std::string kLevels[LVLS];
  const static std::string kComments[LVLS];

  void (Harl::*fp[5])();
  void debug();
  void info();
  void warning();
  void error();
  void undefined();
};

#endif
