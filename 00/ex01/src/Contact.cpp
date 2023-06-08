/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:49:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/08 14:52:05 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#include <iostream>

bool Contact::is_space(int c) {
  if (c == ' ' || c == '\t' || c == '\n')
    return true;
  else
    return false;
}

Contact::Contact() {}
Contact::~Contact() {}

void Contact::print_infos() {
  std::cout << "First Name : " << infos_[kFirstName] << std::endl;
  std::cout << "LastName : " << infos_[kLastName] << std::endl;
  std::cout << "Nickname : " << infos_[kNickname] << std::endl;
  std::cout << "Phone Number : " << infos_[kPhoneNumber] << std::endl;
  std::cout << "Darkest Secret : " << infos_[kDarkestSecret] << std::endl;
}
void Contact::set_input(std::string input) {
  bool wasSpace = true;
  int startIdx = 0;
  int infoIdx = 0;
  for (int i = 0; i < input.length(); i++) {
    if (is_space(input[i])) {
      if (!wasSpace) infos_[infoIdx++] = input.substr(startIdx, i - startIdx);
      wasSpace = true;
    } else {
      if (wasSpace) startIdx = i;
      wasSpace = false;
    }
  }
  if (infoIdx == 4)
    infos_[infoIdx] = input.substr(startIdx, input.length() - startIdx);
}

const std::string &Contact::get_first_name() const {
  return infos_[kFirstName];
}
const std::string &Contact::get_last_name() const { return infos_[kLastName]; }
const std::string &Contact::get_nickname() const { return infos_[kNickname]; }
const std::string &Contact::get_phone_number() const {
  return infos_[kPhoneNumber];
}
const std::string &Contact::get_darkest_secret() const {
  return infos_[kDarkestSecret];
}
