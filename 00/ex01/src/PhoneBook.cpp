/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:51:33 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/08 17:00:35 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <iostream>

#include "Color.hpp"

bool PhoneBook::has_five_fields(std::string str) {
  int fieldCnt = 0;
  bool wasSpace = true;
  for (int i = 0; i < str.length(); i++) {
    if (is_space(str[i]))
      wasSpace = true;
    else {
      if (wasSpace) fieldCnt++;
      wasSpace = false;
    }
  }
  if (fieldCnt == 5)
    return true;
  else
    return false;
}

bool PhoneBook::has_digits_only(std::string str) {
  bool hasDigits = false;
  bool hasWrongChar = false;
  for (int i = 0; i < str.length(); i++) {
    if ('0' <= str[i] && str[i] <= '9')
      hasDigits = true;
    else
      hasWrongChar = true;
  }
  if (hasDigits && !hasWrongChar)
    return true;
  else
    return false;
}

void PhoneBook::print_list() {
  print_info_formatted("index");
  std::cout << "|";
  print_info_formatted("first name");
  std::cout << "|";
  print_info_formatted("last name");
  std::cout << "|";
  print_info_formatted("nickname");
  std::cout << std::endl;
  for (int i = 0; i < num_contacts_; i++) {
    print_info_formatted(std::to_string(i));
    std::cout << "|";
    print_info_formatted(
        contacts_[(oldest_idx_ + i) % kMaxContacts].get_first_name());
    std::cout << "|";
    print_info_formatted(
        contacts_[(oldest_idx_ + i) % kMaxContacts].get_last_name());
    std::cout << "|";
    print_info_formatted(
        contacts_[(oldest_idx_ + i) % kMaxContacts].get_nickname());
    std::cout << std::endl;
  }
}

void PhoneBook::print_info_formatted(std::string str, int width) {
  if (str.length() > width) {
    std::cout << str.substr(0, width - 1) << ".";
  } else {
    std::cout << std::string(width - str.length(), ' ') << str;
  }
}

bool PhoneBook::get_line(std::string *input) {
  getline(std::cin, *input);
  if (std::cin.eof()) {
    std::cin.clear();
    clearerr(stdin);
    return false;
  } else {
    return true;
  }
}

bool PhoneBook::is_space(int c) {
  if (c == ' ' || c == '\t' || c == '\n') {
    return true;
  } else {
    return false;
  }
}

PhoneBook::PhoneBook() : num_contacts_(0), oldest_idx_(0) {}
PhoneBook::~PhoneBook() {}

void PhoneBook::add() {
  std::string input = "";
  while (true) {
    std::cout << color::kYellow << "[ADD]" << color::kEnd;
    std::cout << " Enter a new contact infos to add. " << std::endl;
    std::cout << "format:";
    std::cout << " firstName lastName nickName phoneNumber darkestSecrest ";
    std::cout << std::endl;
    if (!get_line(&input)) {
      std::cout << color::kRed << "error" << color::kEnd;
      std::cout << ": unexpected input (eof)" << std::endl;
    } else if (input == "EXIT") {
      std::cout << "[ADD] Operation cancaled." << std::endl;
      return;
    } else if (!has_five_fields(input)) {
      std::cout << color::kRed << "error" << color::kEnd;
      std::cout << ": invalid input " << std::endl;
    } else {
      break;
    }
  }
  if (num_contacts_ == kMaxContacts) {
    contacts_[oldest_idx_].set_input(input);
    oldest_idx_ = (oldest_idx_ + 1) % kMaxContacts;
  } else {
    contacts_[num_contacts_++].set_input(input);
  }
  std::cout << contacts_[(oldest_idx_ + num_contacts_ - 1) % kMaxContacts]
                   .get_first_name()
            << " "
            << contacts_[(oldest_idx_ + num_contacts_ - 1) % kMaxContacts]
                   .get_last_name()
            << " added successfully." << std::endl;
}

void PhoneBook::search() {
  if (!num_contacts_) {
    std::cout << color::kYellow << "[SEARCH] " << color::kEnd;
    std::cout << "PhoneBook is empty. Please retry after adding a new contact.";
    std::cout << std::endl;
    return;
  }
  std::string input = "";
  while (true) {
    print_list();
    std::cout << color::kYellow << "[SEARCH] " << color::kEnd;
    std::cout << "Enter a index to check informations" << std::endl;
    if (!get_line(&input)) {
      std::cout << color::kRed << "error" << color::kEnd;
      std::cout << ": unexpected input (eof)" << std::endl;
    } else if (input == "EXIT") {
      std::cout << "[SEARCH] Operation cancaled." << std::endl;
      return;
    } else if (!has_digits_only(input)) {
      std::cout << color::kRed << "error" << color::kEnd;
      std::cout << ": invalid input" << std::endl;
    } else if (atoi(input.c_str()) < num_contacts_) {
      contacts_[(oldest_idx_ + atoi(input.c_str())) % kMaxContacts].print_infos();
      break;
    } else {
      std::cout << color::kRed << "error" << color::kEnd;
      std::cout << " invalid index" << std::endl;
    }
  }
}

void PhoneBook::admin() {
  print_info_formatted("index");
  std::cout << "|";
  print_info_formatted("first name");
  std::cout << "|";
  print_info_formatted("last name");
  std::cout << "|";
  print_info_formatted("nickname");
  std::cout << "|";
  print_info_formatted("phone num");
  std::cout << "|";
  print_info_formatted("secret");
  std::cout << std::endl;
  for (int i = 0; i < num_contacts_; i++) {
    print_info_formatted(std::to_string(i));
    std::cout << "|";
    print_info_formatted(contacts_[i].get_first_name());
    std::cout << "|";
    print_info_formatted(contacts_[i].get_last_name());
    std::cout << "|";
    print_info_formatted(contacts_[i].get_nickname());
    std::cout << "|";
    print_info_formatted(contacts_[i].get_phone_number());
    std::cout << "|";
    print_info_formatted(contacts_[i].get_darkest_secret());
    std::cout << std::endl;
  }
}

void PhoneBook::raise_error() {
  std::cout << color::kRed << "error" << color::kEnd;
  std::cout << ": command should be ADD or SEARCH or EXIT" << std::endl;
}