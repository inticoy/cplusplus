/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpanException.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:53:29 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/04 15:42:37 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::DuplicatedElementException::DuplicatedElementException()
    : msg("element duplicated")
{
}
Span::DuplicatedElementException::~DuplicatedElementException() throw() {}
const char *Span::DuplicatedElementException::what() const throw()
{
    return msg.c_str();
}

Span::FullContainerException::FullContainerException() : msg("no space") {}
Span::FullContainerException::~FullContainerException() throw() {}
const char *Span::FullContainerException::what() const throw()
{
    return msg.c_str();
}

Span::EmptyContainerException::EmptyContainerException() : msg("no element") {}
Span::EmptyContainerException::~EmptyContainerException() throw() {}
const char *Span::EmptyContainerException::what() const throw()
{
    return msg.c_str();
}

Span::SingleElementException::SingleElementException() : msg("only one element")
{
}
Span::SingleElementException::~SingleElementException() throw() {}
const char *Span::SingleElementException::what() const throw()
{
    return msg.c_str();
}
