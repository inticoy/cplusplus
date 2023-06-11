/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:14:31 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/11 19:34:55 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>

const std::string Harl::kLevels[LVLS] = {"debug", "info", "warning", "error",
                                         ""};

Harl::Harl() {}
Harl::~Harl() {}

void Harl::complain(std::string level) {
  int lvl_idx = 0;
  size_t found = std::string::npos;
  while (lvl_idx < LVLS && found == std::string::npos) {
    found = level.find(kLevels[lvl_idx++]);
  }

  // typedef void (Harl::*fp)();
  void (Harl::*fp[5])() = {&Harl::debug, &Harl::info, &Harl::warning,
                           &Harl::error, &Harl::undefined};
  // fp fp_arr[5] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error,
  //                 &Harl::undefined};
  (this->*(fp[--lvl_idx]))();
}

void Harl::debug() {
  std::cout << "I love having extra bacon for my ";
  std::cout << "7XL-double-chess-triple-pickle-special-ketchup burger.";
  std::cout << " I really do !" << std::endl;
}
void Harl::info() {
  std::cout << "I cannot believe adding extra bacon costs more money. ";
  std::cout << "You didn't put enough bacon in my burger! ";
  std::cout << "If you did, I wouldn't be asking for more!" << std::endl;
}
void Harl::warning() {
  std::cout << "I think I deserve to have some extra bacon for free. ";
  std::cout << "I've been coming for yeears whereas you started working ";
  std::cout << "here since last month." << std::endl;
}
void Harl::error() {
  std::cout << "This is unacceptable! ";
  std::cout << "I want to speak to the manager now." << std::endl;
}

void Harl::undefined() {
  std::cout << "Undefined level. ";
  std::cout << "Please retry with debug / info / warning / error. ";
  std::cout << std::endl;
}
