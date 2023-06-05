/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:51:33 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/05 17:33:30 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool PhoneBook::isSpace(int c)
{
    if (c == ' ' || c == '\t' || c == '\n')
        return (true);
    else
        return (false);
}

bool PhoneBook::isValidInput(string input)
{
    int fieldCnt = 0;
    bool wasSpace = true;
    for (int i = 0; i < input.length(); i++)
    {
        if (isSpace(input[i]))
            wasSpace = true;
        else
        {
            if (wasSpace)
                fieldCnt++;
            wasSpace = false;
        }
    }
    if (fieldCnt == 5)
        return (true);
    else
        return (false);
}

void PhoneBook::printList(void)
{
    printInfoFormatted("index");
    cout << "|";
    printInfoFormatted("first name");
    cout << "|";
    printInfoFormatted("last name");
    cout << "|";
    printInfoFormatted("nickname");
    cout << endl;
    for (int i = 0; i < numContacts; i++)
    {
        printInfoFormatted(to_string(i));
        cout << "|";
        printInfoFormatted(contacts[i].getFirstName());
        cout << "|";
        printInfoFormatted(contacts[i].getLastName());
        cout << "|";
        printInfoFormatted(contacts[i].getNickname());
        cout << endl;
    }
}

void PhoneBook::printInfoFormatted(string str, int width)
{
    if (str.length() > width)
        cout << str.substr(0, width - 1) << ".";
    else
        cout << string(width - str.length(), ' ') << str;
}

PhoneBook::PhoneBook() : numContacts(0), oldestIdx(-1) {}
PhoneBook::~PhoneBook() {}

void PhoneBook::add()
{
    string input;
    cin.ignore();
    while (true)
    {
        cout << C_YEL "[ADD]" C_END << " Enter a new contact infos to add. "
             << endl;
        cout << "format: firstName lastName nickName phoneNumber darkestSecrest"
             << endl;
        getline(cin, input);
        if (!input.compare("EXIT"))
        {
            cout << "[ADD] Operation cancaled." << endl;
            return;
        }
        else if (!isValidInput(input))
            cout << C_RED "error" C_END << ": invalid input " << endl;
        else
            break;
    }
    if (numContacts == 8)
    {
        contacts[oldestIdx].setInput(input);
        oldestIdx = (oldestIdx + 1) % 8;
    }
    else
    {
        if (numContacts == 0)
            oldestIdx = 0;
        contacts[numContacts].setInput(input);
        numContacts++;
    }
}

void PhoneBook::search()
{
    printList();
    cout << C_YEL "SEARCH" C_END << endl;
};

void PhoneBook::printListAdmin(void)
{
    printInfoFormatted("index");
    cout << "|";
    printInfoFormatted("first name");
    cout << "|";
    printInfoFormatted("last name");
    cout << "|";
    printInfoFormatted("nickname");
    cout << "|";
    printInfoFormatted("phone num");
    cout << "|";
    printInfoFormatted("secret");
    cout << endl;
    for (int i = 0; i < numContacts; i++)
    {
        printInfoFormatted(to_string(i));
        cout << "|";
        printInfoFormatted(contacts[i].getFirstName());
        cout << "|";
        printInfoFormatted(contacts[i].getLastName());
        cout << "|";
        printInfoFormatted(contacts[i].getNickname());
        cout << "|";
        printInfoFormatted(contacts[i].getPhoneNumber());
        cout << "|";
        printInfoFormatted(contacts[i].getDarkestSecret());
        cout << endl;
    }
}