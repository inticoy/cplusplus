/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:49:16 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/03 20:32:35 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(void)
{
    PhoneBook phoneBook;
    string input;
    while (true)
    {
        cin >> input;
        if (!input.compare("ADD"))
            phoneBook.addNewContact();
        else if (!input.compare("SEARCH"))
            phoneBook.search();
        else if (!input.compare("EXIT"))
            break;
        else
            cout << "error : command should be ADD or SEARCH or EXIT" << endl;
    }
    return (0);
}