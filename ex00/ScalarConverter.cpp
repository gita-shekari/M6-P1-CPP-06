/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 02:27:58 by gshekari          #+#    #+#             */
/*   Updated: 2026/07/07 09:25:20 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}
ScalarConverter::ScalarConverter(const ScalarConverter &)
{
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &)
{
	return *this;
}
ScalarConverter::~ScalarConverter()
{

}
type ScalarConverter::detect_type(std::string &literal)
{
	if(literal.length() == 1 && !isdigit(literal[0]))
		return CHAR;
	for(int i = 0; i < literal.length() ; i++)
	{
		if(isdigit(literal[i]))
			return INT;
		if(litral[i] == '.')
		{
			
		}
	}
}
void ScalarConverter::convert(std::string &literal)
{

}
