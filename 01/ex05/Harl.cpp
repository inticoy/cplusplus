/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:14:31 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/15 00:23:04 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>

const std::string Harl::kLevels[LVLS] = {"debug", "info", "warning", "error",
                                         ""};
const std::string Harl::kComments[LVLS] = {
    "I love having extra bacon for my "
    "7XL-double-chess-triple-pickle-special-ketchup burger.\n"
    "I really do !",
    "I cannot believe adding extra bacon costs more money.\n"
    "You didn't put enough bacon in my burger!\n"
    "If you did, I wouldn't be asking for more!",
    "I think I deserve to have some extra bacon for free.\n"
    "I've been coming for yeears whereas you started working "
    "here since last month.",
    "This is unacceptable!\n"
    "I want to speak to the manager now.",
    "Undefined level.\n"
    "Please retry with debug / info / warning / error."};

Harl::Harl() {
  fp[kDebug] = &Harl::debug;
  fp[kInfo] = &Harl::info;
  fp[kWarning] = &Harl::warning;
  fp[kError] = &Harl::error;
  fp[kUndefined] = &Harl::undefined;
  std::cout << "Harl created." << std::endl;
}
Harl::~Harl() { std::cout << "Harl destoryed." << std::endl; }

/* other ways :
 * void (Harl::*fp[5])() = {...}; or
 * typedef void (Harl::*fp)();
 * fp fp_arr[5] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error,
 *                 &Harl::undefined}; */
void Harl::complain(std::string level) {
  int lvl_idx = 0;
  size_t found = std::string::npos;
  while (lvl_idx < LVLS && found == std::string::npos) {
    found = level.find(kLevels[lvl_idx++]);
  }
  (this->*(fp[--lvl_idx]))();
}

void Harl::complain(const char *level) {
  if (!level) {
    std::cout << kComments[kUndefined] << std::endl;
  } else {
    complain(std::string(level));
  }
}

void Harl::debug() { std::cout << kComments[kDebug] << std::endl; }
void Harl::info() { std::cout << kComments[kInfo] << std::endl; }
void Harl::warning() { std::cout << kComments[kWarning] << std::endl; }
void Harl::error() { std::cout << kComments[kError] << std::endl; }
void Harl::undefined() { std::cout << kComments[kUndefined] << std::endl; }
