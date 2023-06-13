/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:22:05 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/13 16:39:58 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
public:
  const static int num_infos_ = 5;
  static std::string info_categories_[5];

  Contact();
  ~Contact();
  void print_infos();
  void set_first_name(std::string);
  void set_last_name(std::string);
  void set_nickname(std::string);
  void set_phone_number(std::string);
  void set_darkest_secret(std::string);
  const std::string &get_first_name() const;
  const std::string &get_last_name() const;
  const std::string &get_nickname() const;
  const std::string &get_phone_number() const;
  const std::string &get_darkest_secret() const;

private:
  enum { kFirstName = 0, kLastName, kNickname, kPhoneNumber, kDarkestSecret };
  std::string infos_[5];
};

#endif