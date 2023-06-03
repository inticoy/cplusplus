/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:15:51 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/03 20:33:35 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class PhoneBook
{
private:
    Contact contacts[8];
    int numContacts;
    int oldestContactIndex;

    bool isValidInput(string input);

public:
    PhoneBook();
    ~PhoneBook();
    void addNewContact();
    void search();
};

#endif