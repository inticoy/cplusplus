/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 22:16:45 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/10 22:17:36 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fed.hpp"

#include <string>

Fed::Fed(std::string file_path, std::string from, std::string to)
    : fs_(),
      file_path_(file_path),
      content_(""),
      result_(""),
      from_(from),
      to_(to) {}
Fed::~Fed() {}

bool Fed::check_file_path() {
  fs_.open(file_path_, std::ios::in);
  if (fs_.is_open()) {
    return true;
  } else {
    return false;
  }
}

void Fed::read_file() {
  char c;
  while (fs_ >> std::noskipws >> c) {
    content_.push_back(c);
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
  fs_.open(file_path_, std::ios::out | std::ios::trunc);
  fs_ << result_;
}

void Fed::close_file() { fs_.close(); }
