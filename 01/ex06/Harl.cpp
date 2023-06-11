/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:14:31 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/11 16:04:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>

const std::string Harl::kLevels[LVLS] = {"DEBUG", "INFO", "WARNING", "ERROR",
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
  // fp fp_arr[5] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error,
  //                 &Harl::undefined};

  switch (--lvl_idx) {
    case 0:
      debug();
    case 1:
      info();
    case 2:
      warning();
    case 3:
      error();
      break;
    default:
      undefined();
  }
}

void Harl::debug() {
  std::cout << "[ DEBUG ]" << std::endl;
  std::cout << "I love having extra bacon for my ";
  std::cout << "7XL-double-chess-triple-pickle-special-ketchup burger.";
  std::cout << std::endl;
  std::cout << " I really do !";
  std::cout << std::endl << std::endl;
}
void Harl::info() {
  std::cout << "[ INFO ]" << std::endl;
  std::cout << "I cannot believe adding extra bacon costs more money. ";
  std::cout << std::endl;
  std::cout << "You didn't put enough bacon in my burger! ";
  std::cout << std::endl;
  std::cout << "If you did, I wouldn't be asking for more!";
  std::cout << std::endl << std::endl;
}
void Harl::warning() {
  std::cout << "[ WARNING ]" << std::endl;
  std::cout << "I think I deserve to have some extra bacon for free. ";
  std::cout << std::endl;
  std::cout << "I've been coming for yeears whereas you started working ";
  std::cout << "here since last month.";
  std::cout << std::endl << std::endl;
}
void Harl::error() {
  std::cout << "[ ERROR ]" << std::endl;
  std::cout << "This is unacceptable! ";
  std::cout << std::endl;
  std::cout << "I want to speak to the manager now.";
  std::cout << std::endl << std::endl;
}

void Harl::undefined() {
  std::cout << "[ Probably complaining about insignificant problems ]";
  std::cout << std::endl;
}
