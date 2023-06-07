/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:15:51 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/07 15:54:38 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Color.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;

class PhoneBook
{
private:
    const static int maxContacts = 8;
    Contact contacts[8];
    int numContacts;
    int oldestIdx;

    bool hasFiveFields(string str);
    bool hasDigitsOnly(string str);
    void printList();
    void printInfoFormatted(string str, int width = 10);

public:
    static bool getLine(string *input);
    static bool isSpace(int c);
    PhoneBook();
    ~PhoneBook();
    void add();
    void search();
    void admin();
};

#endif