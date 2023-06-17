/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 22:16:45 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/17 14:22:18 by gyoon            ###   ########.fr       */
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

void Fed::replace() {
  int cnt = 0;
  int pos = 0;
  int found = 0;
  while (true) {
    found = content_.substr(pos).find(from_);
    if (found == std::string::npos) {
      result_ += content_.substr(pos);
      break;
    } else {
      result_ += content_.substr(pos, found) + to_;
      pos = pos + found + from_.length();
      cnt++;
    }
  }
  std::cout << "total " << cnt << " replacement executed." << std::endl;
}

void Fed::write_file() {
  fs_.open(file_path_ + ".replace", std::ios::out | std::ios::trunc);
  fs_ << result_;
}

void Fed::close_file() { fs_.close(); }
