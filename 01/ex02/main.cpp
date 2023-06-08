/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:36:05 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/08 17:11:17 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
  std::string brain = "HI THIS IS BRAIN";

  std::string *stringPTR = &brain;
  std::string &stringREF = brain;

  std::cout << "string address : " << &brain << std::endl;
  std::cout << "*string address : " << stringPTR << std::endl;
  std::cout << "&string address : " << &stringREF << std::endl;

  std::cout << "string value : " << brain << std::endl;
  std::cout << "*string value : " << *stringPTR << std::endl;
  std::cout << "&string value : " << stringREF << std::endl;
  return 0;
}
