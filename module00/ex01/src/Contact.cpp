/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:49:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/03 20:30:05 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setInput(string input)
{
    int startIdx = 0;
    string infos[5] = {""};
    for (int i = 0; i < 5; i++)
    {
        if (i < 4)
        {
            infos[i] = input.substr(startIdx, input.find(' '));
            startIdx = input.find(' ') + 1;
            input = input.substr(startIdx, input.length() - infos[i].length());
        }
        else
        {
            infos[i] = input;
        }
    }
    this->firstName = infos[0];
    this->lastName = infos[1];
    this->nickName = infos[2];
    this->phoneNumber = infos[3];
    this->darkestSecret = infos[4];
}
