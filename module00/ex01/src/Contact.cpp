/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:49:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/05 16:57:42 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

bool Contact::isSpace(int c)
{
    if (c == ' ' || c == '\t' || c == '\n')
        return (true);
    else
        return (false);
}

Contact::Contact() {}
Contact::~Contact() {}

void Contact::setInput(string input)
{
    bool wasSpace = true;
    int startIdx = 0;
    int infoIdx = 0;
    for (int i = 0; i < input.length(); i++)
    {
        if (isSpace(input[i]))
        {
            if (!wasSpace)
                infos[infoIdx++] = input.substr(startIdx, i - startIdx);
            wasSpace = true;
        }
        else
        {
            if (wasSpace)
                startIdx = i;
            wasSpace = false;
        }
    }
    if (infoIdx == 4)
        infos[infoIdx] = input.substr(startIdx, input.length() - startIdx);
}

string Contact::getFirstName() { return (infos[FirstName]); }
string Contact::getLastName() { return (infos[LastName]); }
string Contact::getNickname() { return (infos[Nickname]); }
string Contact::getPhoneNumber() { return (infos[PhoneNumber]); }
string Contact::getDarkestSecret() { return (infos[DarkestSecret]); }
