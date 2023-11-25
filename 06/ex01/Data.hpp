/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:51:56 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/25 14:56:54 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

class Data
{
  public:
    Data();
    Data(const Data &other);
    Data(int number);
    Data &operator=(const Data &other);
    ~Data();

  private:
    int number;
};

#endif