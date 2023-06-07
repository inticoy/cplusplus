/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:36:05 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/07 16:00:47 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
    string brain = "HI THIS IS BRAIN";

    string *stringPTR = &brain;
    string &stringREF = brain;

    cout << "string address : " << &brain << endl;
    cout << "*string address : " << stringPTR << endl;
    cout << "&string address : " << &stringREF << endl;

    cout << "string value : " << brain << endl;
    cout << "*string value : " << *stringPTR << endl;
    cout << "&string value : " << stringREF << endl;
    return 0;
}
