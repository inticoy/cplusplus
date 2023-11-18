/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AFormException.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:15:22 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/18 18:34:36 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char *AForm::GradeTooHighException::what() const throw()
{
    return "grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "grade is too low";
}

const char *AForm::DoubleSignException::what() const throw()
{
    return "form is already signed";
}

const char *AForm::NotSignedException::what() const throw()
{
    return "form is not signed yet";
}