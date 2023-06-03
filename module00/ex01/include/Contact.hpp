/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:22:05 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/03 20:55:48 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

using std::string;

class Contact
{
private:
public:
    string firstName;
    string lastName;
    string nickName;
    string phoneNumber;
    string darkestSecret;
    Contact();
    ~Contact();
    void setInput(string input);
};

#endif