/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:13:56 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/11 15:52:53 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>

#define LVLS 5

class Harl {
public:
  Harl();
  ~Harl();
  void complain(std::string level);

private:
  const static std::string kLevels[LVLS];

  void debug();
  void info();
  void warning();
  void error();
  void undefined();
};

#endif
