/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:15:51 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/08 15:10:21 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <string>

#include "Contact.hpp"

class PhoneBook {
public:
  static bool get_line(std::string *input);
  static bool is_space(int c);
  PhoneBook();
  ~PhoneBook();
  void add();
  void search();
  void admin();
  void raise_error();

private:
  const static int kMaxContacts = 8;
  int num_contacts;
  int oldest_idx;
  Contact contacts[8];

  bool has_five_fields(std::string str);
  bool has_digits_only(std::string str);
  void print_list();
  void print_info_formatted(std::string str, int width = 10);
};

#endif