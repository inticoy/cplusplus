/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:56:19 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/14 23:44:28 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Harl.hpp"

int main() {
  Harl harl;
  std::cout << color::kYellow << "[DEBUG level]" << color::kEnd << std::endl;
  harl.complain("debug");
  std::cout << color::kYellow << "[INFO level]" << color::kEnd << std::endl;
  harl.complain("info");
  std::cout << color::kYellow << "[WARNING level]" << color::kEnd << std::endl;
  harl.complain("warning");
  std::cout << color::kYellow << "[ERROR level]" << color::kEnd << std::endl;
  harl.complain("error");

  std::cout << color::kRed << "[UNDEFINED level]" << color::kEnd << std::endl;
  harl.complain("");
  std::cout << color::kRed << "[UNDEFINED level]" << color::kEnd << std::endl;
  harl.complain("undefined");
  std::cout << color::kRed << "[UNDEFINED level]" << color::kEnd << std::endl;
  harl.complain(0);
  return 0;
}
