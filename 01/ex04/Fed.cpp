/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 22:16:45 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/14 23:10:51 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fed.hpp"

#include <iostream>
#include <string>

Fed::Fed(std::string file_path, std::string from, std::string to)
    : fs_(),
      file_path_(file_path),
      content_(""),
      result_(""),
      from_(from),
      to_(to) {}
Fed::~Fed() {}

/* open in unistd.h || stat in sys/stat.h are forbiddened.
 * in c++98, there is no way to know a file is a directory without using c func.
 * in c++17, std::filesystem::is_directory returns a file is a directory or not.
 * therefore, check_file_path just checks file_path_ is valid or not.
 * */
bool Fed::check_file_path() {
  fs_.open(file_path_, std::ios::in);
  if (fs_.is_open()) {
    return true;
  } else {
    return false;
  }
}

/* std::noskipws is an I/O manipulator that can be used with only input streams
 * when std::noskipws is set, whitespaces(space, tab, newline) will be entered.
 * std::ws can make just like as before calling std::noskipws.
 * */
void Fed::read_file() {
  char c;
  while (fs_ >> std::noskipws >> c) {
    content_.push_back(c);
  }
  if (content_.length() == 0) {
    std::cout << "warning: ";
    std::cout << file_path_ << " has no content or is a directory.";
    std::cout << std::endl;
  }
}

int Fed::replace() {
  int cnt = 0;
  for (int i = 0; i < content_.length(); i++) {
    if (content_.substr(i, from_.length()) == from_) {
      result_ += to_;
      i += from_.length() - 1;
      cnt++;
    } else {
      result_ += content_[i];
    }
  }
  return cnt;
}

void Fed::write_file() {
  fs_.open(file_path_ + ".replace", std::ios::out | std::ios::trunc);
  fs_ << result_;
}

void Fed::close_file() { fs_.close(); }
