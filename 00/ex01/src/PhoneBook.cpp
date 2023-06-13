/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:51:33 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/13 17:05:23 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <cctype>
#include <iostream>

#include "Color.hpp"

bool PhoneBook::has_one_field(std::string str) {
  int fieldCnt = 0;
  bool wasSpace = true;
  for (int i = 0; i < str.length(); i++) {
    if (std::isspace(str[i]))
      wasSpace = true;
    else {
      if (wasSpace) fieldCnt++;
      wasSpace = false;
    }
  }
  if (fieldCnt == 1)
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
  for (int i = 0; i < 3; i++) {
    std::cout << "|";
    print_info_formatted(Contact::info_categories_[i]);
  }
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

PhoneBook::PhoneBook() : kMaxContacts(8), num_contacts_(0), oldest_idx_(0) {}
PhoneBook::~PhoneBook() {}

void PhoneBook::add() {
  std::string input = "";
  std::string infos[5] = {};
  std::cout << color::kYellow << "[ADD]" << color::kEnd;
  std::cout << " Enter a new contact infos to add. " << std::endl;
  for (int i = 0; i < Contact::num_infos_; i++) {
    std::cout << Contact::info_categories_[i] << " : ";
    if (!get_line(&input)) {
      std::cout << std::endl;
      std::cout << color::kRed << "error" << color::kEnd;
      std::cout << ": unexpected input (eof)" << std::endl;
      i--;
      continue;
    } else if (input == "EXIT") {
      std::cout << "[ADD] Operation cancaled." << std::endl;
      return;
    } else if (!has_one_field(input)) {
      std::cout << color::kRed << "error" << color::kEnd;
      std::cout << ": enter one field at once " << std::endl;
      i--;
      continue;
    } else {
      int startIdx = 0;
      int len = input.length();
      for (startIdx = 0; startIdx < len; startIdx++) {
        if (!std::isspace(input[startIdx])) {
          break;
        }
      }
      len = input.length() - startIdx;
      while (len > 0) {
        if (!std::isspace(input[startIdx + len - 1])) {
          break;
        }
        len--;
      }
      infos[i] = input.substr(startIdx, len);
    }
  }
  if (num_contacts_ == kMaxContacts) {
    contacts_[oldest_idx_].set_first_name(infos[0]);
    contacts_[oldest_idx_].set_last_name(infos[1]);
    contacts_[oldest_idx_].set_nickname(infos[2]);
    contacts_[oldest_idx_].set_phone_number(infos[3]);
    contacts_[oldest_idx_].set_darkest_secret(infos[4]);
    oldest_idx_ = (oldest_idx_ + 1) % kMaxContacts;
  } else {
    contacts_[num_contacts_].set_first_name(infos[0]);
    contacts_[num_contacts_].set_last_name(infos[1]);
    contacts_[num_contacts_].set_nickname(infos[2]);
    contacts_[num_contacts_].set_phone_number(infos[3]);
    contacts_[num_contacts_].set_darkest_secret(infos[4]);
    num_contacts_++;
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
      contacts_[(oldest_idx_ + atoi(input.c_str())) % kMaxContacts]
          .print_infos();
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