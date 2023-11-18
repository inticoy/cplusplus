/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:57:46 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/18 18:33:29 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>

int main()
{
    AForm *form = new ShrubberyCreationForm("hi");
    Bureaucrat man("Kim", 1);
    Bureaucrat man2("Lee", 150);

    man2.executeForm(*form);
    man.executeForm(*form);
    man2.signForm(*form);
    man.signForm(*form);
    man2.executeForm(*form);
    man.executeForm(*form);

    return 0;
}
