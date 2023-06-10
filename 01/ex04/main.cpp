/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:56:19 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/10 17:01:54 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  if (argc != 4) {
    std::cout << "usage: ./Sed_is_for_losers filename s1 s2" << std::endl;
    return 0;
  }
  std::string path = std::string(argv[1]);
  std::string before = std::string(argv[2]);
  std::string after = std::string(argv[3]);

  std::string str = "";
  char c;

  std::ifstream fin(path);
  if (!fin.is_open()) std::cout << "not opened" << std::endl;
  while (fin >> std::noskipws >> c) {
    str.push_back(c);
  }
  // std::cout << str << std::endl;

  std::string result = "";

  for (int i = 0; i < str.length(); i++) {
    if (str.substr(i, before.length()) == before) {
      // std::cout << before << std::endl;
      result += after;
      i += before.length() - 1;
    } else {
      result += str[i];
    }
  }

  std::cout << result;

  return 0;
}