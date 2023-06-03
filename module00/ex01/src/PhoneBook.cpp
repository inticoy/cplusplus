/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:51:33 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/03 20:58:33 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : numContacts(0), oldestContactIndex(-1)
{
    for (int i = 0; i < 8; i++)
        contacts[i] = Contact();
}

PhoneBook::~PhoneBook() {}

bool PhoneBook::isValidInput(string input)
{
    int numSpace = 0;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ' ')
            numSpace++;
    }
    if (numSpace == 4)
        return (true);
    else
        return (false);
}

void PhoneBook::addNewContact()
{
    string input;
    cin.ignore();
    while (true)
    {
        cout << "Enter a new contact infos to add. "
             << "(firstName lastName nickName phoneNumber darkestSecrest)"
             << endl
             << "enter : ";
        getline(cin, input);
        if (!isValidInput(input))
        {
            cout << "error : invalid input" << endl;
            continue;
        }
        else
            break;
    }
    if (numContacts == 8)
    {
        contacts[oldestContactIndex].setInput(input);
        oldestContactIndex = (oldestContactIndex + 1) % 8;
    }
    else
    {
        if (numContacts == 0)
            oldestContactIndex = 0;
        contacts[numContacts].setInput(input);
        numContacts++;
    }
}

void PhoneBook::search()
{
    for (int i = 0; i < numContacts; i++)
    {
        cout << contacts[(oldestContactIndex + i) % numContacts].firstName
             << endl;
    }
};
