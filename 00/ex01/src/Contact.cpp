/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:49:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/13 16:48:26 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#include <cctype>
#include <iostream>

std::string Contact::info_categories_[5] = {
    "First Name", "Last Name", "Nickname", "Phone Number", "Darkest Secret"};

Contact::Contact() {}
Contact::~Contact() {}

void Contact::print_infos() {
  for (int i = 0; i < num_infos_; i++) {
    std::cout << info_categories_[i] << " : " << infos_[i] << std::endl;
  }
}

void Contact::set_first_name(std::string first_name) {
  infos_[kFirstName] = first_name;
}
void Contact::set_last_name(std::string last_name) {
  infos_[kLastName] = last_name;
}
void Contact::set_nickname(std::string nickname) {
  infos_[kNickname] = nickname;
}
void Contact::set_phone_number(std::string phone_number) {
  infos_[kPhoneNumber] = phone_number;
}
void Contact::set_darkest_secret(std::string darkest_secret) {
  infos_[kDarkestSecret] = darkest_secret;
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
