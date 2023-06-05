/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:22:05 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/05 16:53:25 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

using std::string;

class Contact
{
private:
    enum InfoIdx
    {
        FirstName,
        LastName,
        Nickname,
        PhoneNumber,
        DarkestSecret
    };
    string infos[5];
    bool isSpace(int c);

public:
    Contact();
    ~Contact();
    void setInput(string input);
    string getFirstName();
    string getLastName();
    string getNickname();
    string getPhoneNumber();
    string getDarkestSecret();
};

#endif