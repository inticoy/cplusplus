/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:44:27 by inticoy           #+#    #+#             */
/*   Updated: 2023/06/08 10:26:51 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  if (argc == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  else {
    for (int i = 1; i < argc; i++) {
      std::string str = std::string(argv[i]);
      for (int j = 0; j < str.length(); j++) {
        str[j] = toupper(str[j]);
      }
      std::cout << str;
    }
    std::cout << std::endl;
  }
  return 0;
}
