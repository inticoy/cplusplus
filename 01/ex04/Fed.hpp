/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 22:16:57 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/17 14:10:52 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FED_HPP
#define FED_HPP

#include <fstream>
#include <string>

class Fed {
public:
  Fed(std::string file_path, std::string from, std::string to);
  ~Fed();
  bool check_file_path();
  void read_file();
  void replace();
  void write_file();
  void close_file();

private:
  std::fstream fs_;
  std::string file_path_;
  std::string content_;
  std::string result_;
  std::string from_;
  std::string to_;
};

#endif
