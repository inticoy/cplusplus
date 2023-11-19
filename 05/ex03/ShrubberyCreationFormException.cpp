/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationFormException.cpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:37:46 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/19 14:02:35 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::FileCreateFailException::
    FileCreateFailException() throw()
    : msg("failed to create file")
{
}

ShrubberyCreationForm::FileCreateFailException::
    ~FileCreateFailException() throw()
{
}

const char *ShrubberyCreationForm::FileCreateFailException::what() const throw()
{
    return "failed to create file";
}
