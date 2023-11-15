/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:57:46 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/15 20:28:11 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>

int main()
{
    Form form("Application for Leave", 75, 75);
    Bureaucrat president("Kim", 1);
    Bureaucrat servant("Lee", 150);

    std::cout << form << std::endl;

    std::cout << "\n[TEST 1]\n";
    servant.signForm(form);

    std::cout << "\n[TEST 2]\n";
    president.signForm(form);

    std::cout << "\n[TEST 3]\n";
    president.signForm(form);

    std::cout << "\n[TEST 4]\n";
    try
    {
        Form *form = new Form("test", 1, 160);
        std::cout << form << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
