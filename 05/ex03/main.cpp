/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:57:46 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/30 17:24:42 by gyoon            ###   ########.fr       */
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
        std::cout << "TEST 1" << '\n';

        AForm *form = intern.makeForm("shrubbery creation", "home");
        Bureaucrat president("Kim", 1);
        Bureaucrat servant("Lee", 150);

        servant.executeForm(*form);
        president.executeForm(*form);
        servant.signForm(*form);
        president.signForm(*form);
        servant.executeForm(*form);
        president.executeForm(*form);

        delete form;
    }

    {
        std::cout << '\n' << "TEST 2" << '\n';
        AForm *form = intern.makeForm("robotomY Request", "Gyoon");
        Bureaucrat president("Kim", 1);
        Bureaucrat servant("Lee", 150);

        servant.executeForm(*form);
        president.executeForm(*form);
        servant.signForm(*form);
        president.signForm(*form);
        servant.executeForm(*form);
        president.executeForm(*form);

        delete form;
    }

    {
        std::cout << '\n' << "TEST 3" << '\n';
        AForm *form = intern.makeForm("presIDential pardon", "gyoon");
        Bureaucrat president("Kim", 1);
        Bureaucrat servant("Lee", 150);

        servant.executeForm(*form);
        president.executeForm(*form);
        servant.signForm(*form);
        president.signForm(*form);
        servant.executeForm(*form);
        president.executeForm(*form);

        delete form;
    }

    {
        std::cout << '\n' << "TEST 4" << '\n';
        AForm *form = intern.makeForm("wrong request", "target");
        delete form;
    }

    return 0;
}
