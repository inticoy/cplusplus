/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:39:36 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/15 22:22:44 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreation", 145, 137), target("temp")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &scf)
    : AForm(scf.getName(), scf.getMinSignGrade(), scf.getMinExeGrade()),
      target(scf.target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreation", 145, 137), target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

const ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm &scf)
{
    target = scf.target;
    return (*this);
}

bool ShrubberyCreationForm::execute(const Bureaucrat &e) const
    throw(GradeTooLowException)
{
    if (!this->getIsSigned())
    {
        return false;
    }
    else if (e.getGrade() > this->getMinExeGrade())
    {
        throw(GradeTooLowException());
    }
    else
    {
        std::cout << "                                            .\n";
        std::cout << "                                   .         ;\n";
        std::cout << "      .              .              ;%%     ;;\n";
        std::cout << "        ,           ,                :;%%  %%;\n";
        std::cout << "         :         ;                   :;%%;'     .,\n";
        std::cout << ",.        %%;     %%;            ;        %%;'    ,;\n";
        std::cout << "  ;       ;%%;  %%%%;        ,     %%;    ;%%;    ,%%'\n";
        std::cout << "   %%;       %%;%%;      ,  ;       %%;  ;%%;   ,%%;'\n";
        std::cout << "    ;%%;      %%;        ;%%;        %% ;%%;  ,%%;'\n";
        std::cout << "     `%%;.     ;%%;     %%;'         `;%%%%;.%%;'\n";
        std::cout << "      `:;%%.    ;%%%%. %%@;        %%; ;@%%;%%'\n";
        std::cout << "         `:%%;.  :;bd%%;          %%;@%%;'\n";
        std::cout << "           `@%%:.  :;%%.         ;@@%%;'\n";
        std::cout << "             `@%%.  `;@%%.      ;@@%%;\n";
        std::cout << "               `@%%%%. `@%%%%    ;@@%%;\n";
        std::cout << "                 ;@%%. :@%%%%  %%@@%%;\n";
        std::cout << "                   %%@bd%%%%%%bd%%%%:;\n";
        std::cout << "                     #@%%%%%%%%%%:;;\n";
        std::cout << "                     %%@@%%%%%%::;\n";
        std::cout << "                     %%@@@%%(o);  . '\n";
        std::cout << "                     %%@@@o%%;:(.,'\n";
        std::cout << "                 `.. %%@@@o%%::;\n";
        std::cout << "                    `)@@@o%%::;\n";
        std::cout << "                     %%@@(o)::;\n";
        std::cout << "                    .%%@@@@%%::;\n";
        std::cout << "                    ;%%@@@@%%::;.\n";
        std::cout << "                   ;%%@@@@%%%%:;;;.\n";
        std::cout << "               ...;%@@@@@%%:;;;;,..\n";
        return true;
    }
}
