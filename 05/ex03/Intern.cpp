/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:44:57 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/19 22:09:27 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &i)
{
    (void)i;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &i)
{
    (void)i;
    return *this;
}

std::string Intern::strtolower(const std::string &str) const
{
    std::string lower = "";
    for (size_t i = 0; i < str.length(); i++)
    {
        lower += std::tolower(str.at(i));
    }
    return lower;
}

AForm *Intern::makePresidentialPardonForm(const std::string &target) const
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeRobotomyRequestForm(const std::string &target) const
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::makeShrubberyCreationForm(const std::string &target) const
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(const std::string &formName,
                        const std::string &target) const
{
    AForm *(Intern::*funcs[])(const std::string &target) const = {
        &Intern::makePresidentialPardonForm, &Intern::makeRobotomyRequestForm,
        &Intern::makeShrubberyCreationForm};
    std::string formNames[3] = {"presidential pardon", "robotomy request",
                                "shrubbery creation"};

    for (int i = 0; i < 3; i++)
    {
        if (strtolower(formNames[i]) == strtolower(formName))
        {
            AForm *form = (this->*funcs[i])(target);
            std::cout << "Intern creates " << formName << std::endl;
            return form;
        }
    }
    std::cerr << "Intern failed to create " << formName << std::endl;
    return NULL;
}
