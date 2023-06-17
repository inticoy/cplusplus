/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:56:19 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/17 14:10:12 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Fed.hpp"

int main(int argc, char *argv[]) {
  if (argc != 4) {
    std::cout << "usage: ./Sed_is_for_losers filename s1 s2" << std::endl;
    return 0;
  }
  Fed fed(argv[1], argv[2], argv[3]);
  if (!fed.check_file_path()) {
    std::cout << "error: file does not exist." << std::endl;
  } else {
    fed.read_file();
    fed.replace();
    fed.close_file();
    fed.write_file();
    fed.close_file();
  }
  return 0;
}
