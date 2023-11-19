/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:57:46 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/19 14:59:26 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>

int main()
{
    {
        std::cout << "\nTEST 1\n";
        AForm *form = new ShrubberyCreationForm("test");
        Bureaucrat man("Kim", 1);
        Bureaucrat man2("Lee", 150);

        man2.executeForm(*form);
        man.executeForm(*form);
        man2.signForm(*form);
        man.signForm(*form);
        man2.executeForm(*form);
        man.executeForm(*form);

        delete form;
    }

    {
        std::cout << "\nTEST 2\n";
        AForm *form = new RobotomyRequestForm("gyoon");
        Bureaucrat man("Kim", 1);
        Bureaucrat man2("Lee", 150);

        man2.executeForm(*form);
        man.executeForm(*form);
        man2.signForm(*form);
        man.signForm(*form);
        man2.executeForm(*form);
        man.executeForm(*form);
        man.executeForm(*form);
        man.executeForm(*form);
        man.executeForm(*form);

        delete form;
    }

    {
        std::cout << "\nTEST 3\n";
        AForm *form = new PresidentialPardonForm("gyoon");
        Bureaucrat man("Kim", 1);
        Bureaucrat man2("Lee", 150);

        man2.executeForm(*form);
        man.executeForm(*form);
        man2.signForm(*form);
        man.signForm(*form);
        man2.executeForm(*form);
        man.executeForm(*form);

        delete form;
    }

    return 0;
}
