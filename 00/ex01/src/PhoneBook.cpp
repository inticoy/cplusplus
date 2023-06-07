/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:51:33 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/07 15:56:43 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool PhoneBook::hasFiveFields(string str)
{
    int fieldCnt = 0;
    bool wasSpace = true;
    for (int i = 0; i < str.length(); i++)
    {
        if (isSpace(str[i]))
            wasSpace = true;
        else
        {
            if (wasSpace)
                fieldCnt++;
            wasSpace = false;
        }
    }
    if (fieldCnt == 5)
        return true;
    else
        return false;
}

bool PhoneBook::hasDigitsOnly(string str)
{
    bool hasDigits = false;
    bool hasWrongChar = false;
    for (int i = 0; i < str.length(); i++)
    {
        if ('0' <= str[i] && str[i] <= '9')
            hasDigits = true;
        else
            hasWrongChar = true;
    }
    if (hasDigits && !hasWrongChar)
        return true;
    else
        return false;
}

void PhoneBook::printList()
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
        printInfoFormatted(
            contacts[(oldestIdx + i) % maxContacts].getFirstName());
        cout << "|";
        printInfoFormatted(
            contacts[(oldestIdx + i) % maxContacts].getLastName());
        cout << "|";
        printInfoFormatted(
            contacts[(oldestIdx + i) % maxContacts].getNickname());
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

bool PhoneBook::getLine(string *input)
{
    getline(cin, *input);
    if (cin.eof())
    {
        cin.clear();
        clearerr(stdin);
        return false;
    }
    else
        return true;
}

bool PhoneBook::isSpace(int c)
{
    if (c == ' ' || c == '\t' || c == '\n')
        return true;
    else
        return false;
}

PhoneBook::PhoneBook() : numContacts(0), oldestIdx(0) {}
PhoneBook::~PhoneBook() {}

void PhoneBook::add()
{
    string input = "";
    while (true)
    {
        cout << C_YEL "[ADD]" C_END;
        cout << " Enter a new contact infos to add. " << endl;
        cout << "format: firstName lastName nickName phoneNumber darkestSecrest"
             << endl;
        if (getLine(&input))
        {
            if (!input.compare("EXIT"))
            {
                cout << "[ADD] Operation cancaled." << endl;
                return;
            }
            else if (!hasFiveFields(input))
                cout << C_RED "error" C_END << ": invalid input " << endl;
            else
                break;
        }
        else
            cout << C_RED "error" C_END << ": unexpected input (eof)" << endl;
    }
    if (numContacts == maxContacts)
    {
        contacts[oldestIdx].setInput(input);
        oldestIdx = (oldestIdx + 1) % maxContacts;
    }
    else
        contacts[numContacts++].setInput(input);
    cout << contacts[(oldestIdx + numContacts - 1) % maxContacts].getFirstName()
         << " "
         << contacts[(oldestIdx + numContacts - 1) % maxContacts].getLastName()
         << " added successfully." << endl;
}

void PhoneBook::search()
{
    if (!numContacts)
    {
        cout << C_YEL "[SEARCH] " C_END;
        cout << "PhoneBook is empty. Please retry after adding a new contact."
             << endl;
        return;
    }
    string input = "";
    while (true)
    {
        printList();
        cout << C_YEL "[SEARCH] " C_END;
        cout << "Enter a index to check informations" << endl;
        if (getLine(&input))
        {
            if (!input.compare("EXIT"))
            {
                cout << "[SEARCH] Operation cancaled." << endl;
                return;
            }
            else if (!hasDigitsOnly(input))
                cout << C_RED "error: invalid input" C_END << endl;
            else if (atoi(input.c_str()) < numContacts)
            {
                contacts[(oldestIdx + atoi(input.c_str())) % maxContacts]
                    .printInfos();
                break;
            }
            else
                cout << C_RED "error: invalid index" C_END << endl;
        }
        else
            cout << C_RED "error" C_END << ": unexpected input (eof)" << endl;
    }
}

void PhoneBook::admin()
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