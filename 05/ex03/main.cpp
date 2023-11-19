/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:57:46 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/19 22:12:25 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>

int main()
{
    Intern intern;
    {
        std::cout << "\nTEST 1\n";
        AForm *form = intern.makeForm("shrubbery creation", "home");
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
        AForm *form = intern.makeForm("robotomY Request", "Gyoon");
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
        std::cout << "\nTEST 3\n";
        AForm *form = intern.makeForm("presidential pardon", "gyoon");
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
        std::cout << "\nTEST 4\n";
        AForm *form = intern.makeForm("no exist", "target");

        delete form;
    }

    return 0;
}
