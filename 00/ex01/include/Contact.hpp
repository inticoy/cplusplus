/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:22:05 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/08 14:42:37 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
public:
  Contact();
  ~Contact();
  void print_infos();
  void set_input(std::string input);
  const std::string &get_first_name() const;
  const std::string &get_last_name() const;
  const std::string &get_nickname() const;
  const std::string &get_phone_number() const;
  const std::string &get_darkest_secret() const;

private:
  enum { kFirstName = 0, kLastName, kNickname, kPhoneNumber, kDarkestSecret };
  std::string infos_[5];

  bool is_space(int c);
};

#endif