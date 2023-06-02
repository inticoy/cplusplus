/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:44:27 by inticoy           #+#    #+#             */
/*   Updated: 2023/06/02 17:26:57 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
    string str = string(argv[i]);
    for (int i = 0; i < str.length(); i++) str[i] = toupper(str[i]);
    cout << str << endl;
  }
  return 0;
}
