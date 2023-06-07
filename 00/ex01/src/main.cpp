/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:49:16 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/07 15:56:51 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    PhoneBook phoneBook = PhoneBook();
    string input = "";
    while (true)
    {
        cout << C_BLU "[Phone Book App]" C_END
             << " Enter ADD or SEARCH or EXIT to Use." << endl;
        if (PhoneBook::getLine(&input))
        {
            if (!input.compare("ADD"))
                phoneBook.add();
            else if (!input.compare("SEARCH"))
                phoneBook.search();
            else if (!input.compare("ADMIN"))
                phoneBook.admin();
            else if (!input.compare("EXIT"))
                break;
            else
                cout << C_RED "error" C_END
                     << ": command should be ADD or SEARCH or EXIT" << endl;
        }
        else
            cout << C_RED "error" C_END << ": unexpected input (eof)" << endl;
    }
    cout << C_BLU "[Phone Book App]" C_END << " Exit" << endl;
    return 0;
}