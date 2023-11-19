/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:39:36 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/19 15:13:43 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation Form", 145, 137), target("temp")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &sf)
    : AForm(sf.getName(), sf.getMinSignGrade(), sf.getMinExeGrade()),
      target(sf.target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubbery Creation Form", 145, 137), target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm &sf)
{
    if (this != &sf)
    {
        this->setIsSigned(sf.getIsSigned());
        target = sf.target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &e) const
    throw(GradeTooLowException, NotSignedException)
{
    checkRequirements(e);
    std::string filename;
    filename = target + "_shrubbery";
    std::fstream fs;
    fs.open(filename.c_str(), std::ios::out | std::ios::trunc);
    if (!fs.is_open())
    {
        throw FileCreateFailException();
    }
    fs << "                                            .\n";
    fs << "                                   .         ;\n";
    fs << "      .              .              ;%%     ;;\n";
    fs << "        ,           ,                :;%%  %%;\n";
    fs << "         :         ;                   :;%%;'     .,\n";
    fs << ",.        %%;     %%;            ;        %%;'    ,;\n";
    fs << "  ;       ;%%;  %%%%;        ,     %%;    ;%%;    ,%%'\n";
    fs << "   %%;       %%;%%;      ,  ;       %%;  ;%%;   ,%%;'\n";
    fs << "    ;%%;      %%;        ;%%;        %% ;%%;  ,%%;'\n";
    fs << "     `%%;.     ;%%;     %%;'         `;%%%%;.%%;'\n";
    fs << "      `:;%%.    ;%%%%. %%@;        %%; ;@%%;%%'\n";
    fs << "         `:%%;.  :;bd%%;          %%;@%%;'\n";
    fs << "           `@%%:.  :;%%.         ;@@%%;'\n";
    fs << "             `@%%.  `;@%%.      ;@@%%;\n";
    fs << "               `@%%%%. `@%%%%    ;@@%%;\n";
    fs << "                 ;@%%. :@%%%%  %%@@%%;\n";
    fs << "                   %%@bd%%%%%%bd%%%%:;\n";
    fs << "                     #@%%%%%%%%%%:;;\n";
    fs << "                     %%@@%%%%%%::;\n";
    fs << "                     %%@@@%%(o);  . '\n";
    fs << "                     %%@@@o%%;:(.,'\n";
    fs << "                 `.. %%@@@o%%::;\n";
    fs << "                    `)@@@o%%::;\n";
    fs << "                     %%@@(o)::;\n";
    fs << "                    .%%@@@@%%::;\n";
    fs << "                    ;%%@@@@%%::;.\n";
    fs << "                   ;%%@@@@%%%%:;;;.\n";
    fs << "               ...;%@@@@@%%:;;;;,..\n";
    fs.close();
}
