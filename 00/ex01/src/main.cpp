/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:49:16 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/08 15:15:44 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Color.hpp"
#include "Contact.hpp"
#include "PhoneBook.hpp"

const std::string kPhoneBookApp = "[Phone Book App]";

int main() {
  PhoneBook phone_book = PhoneBook();
  std::string input = "";
  while (true) {
    std::cout << color::kBlue << kPhoneBookApp << color::kEnd;
    std::cout << " Enter ADD or SEARCH or EXIT to Use." << std::endl;
    if (!PhoneBook::get_line(&input)) {
      std::cout << color::kRed + "error" + color::kEnd;
      std::cout << ": unexpected input (eof)" << std::endl;
    } else if (input == "ADD") {
      phone_book.add();
    } else if (input == "SEARCH") {
      phone_book.search();
    } else if (input == "ADMIN") {
      phone_book.admin();
    } else if (input == "EXIT") {
      break;
    } else {
      phone_book.raise_error();
    }
  }
  std::cout << color::kBlue << kPhoneBookApp << color::kEnd;
  std::cout << " Exit" << std::endl;
  return 0;
}
