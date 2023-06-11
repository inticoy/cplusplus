/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:56:19 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/11 15:49:27 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Harl.hpp"

int main() {
  Harl harl;
  harl.complain("debug");
  harl.complain("info");
  harl.complain("warning");
  harl.complain("error");
  harl.complain("");
  harl.complain("undefined");
  return 0;
}
