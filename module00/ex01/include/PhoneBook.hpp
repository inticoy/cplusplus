/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:15:51 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/06 15:53:16 by gyoon            ###   ########.fr       */
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

    bool isValidInput(string input);
    void printList(void);
    void printInfoFormatted(string str, int width = 10);

public:
    PhoneBook();
    ~PhoneBook();
    bool isSpace(int c);
    void add();
    void search();
    void admin(void);
};

#endif