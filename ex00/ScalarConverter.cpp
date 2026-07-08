/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 02:27:58 by gshekari          #+#    #+#             */
/*   Updated: 2026/07/08 04:12:34 by gshekari         ###   ########.fr       */
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
ScalarConverter::type ScalarConverter::detect_type(const std::string &literal)
{
	if (literal.empty())
		return INVALID;
	if(literal == "nan")
		return NNAN;
	if(literal == "+inf")
		return INF_P;
	if(literal == "-inf")
		return INF_M;
	if (literal.length() == 1 && !std::isdigit(literal[0]))
	{
		if(literal[0] == '.' || literal[0] == '+' || literal[0] == '-')
			return INVALID;
		else
			return CHAR;
	}
	bool has_f = false;
	bool has_dot = false;
	for(size_t i = 0; i < literal.length() ; i++)
	{
		if(literal[i] == '.' && !has_dot)
			has_dot = true;
		else if(literal[i] == 'f' && i == literal.length() -1 && !has_f)
			has_f = true;
		else if(!std::isdigit(literal[i]) && !(i == 0 && (literal[i] == '+' || literal[i] == '-')))
			return INVALID;
	}
	if (has_f && !has_dot)
		return INVALID;
	if(has_f && has_dot)
		return FLOAT;
	if(has_dot)
		return DOUBLE;
	return INT;
}

void ScalarConverter::handle_special_literals(type t)
{
	if (t == NNAN)
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
	}
	else if (t == INF_P)
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: +inff\n";
		std::cout << "double: +inf\n";
	}
	else if(t == INF_M)
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: -inff\n";
		std::cout << "double: -inf\n";
	}
}
void ScalarConverter::handle_char(char c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}
void ScalarConverter::handle_int(int i)
{
	if (i < 0 || i > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(i))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}
void ScalarConverter::handle_float(float f)
{
	int i = static_cast<int>(f);

	if (f < 0 || f > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(i))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	if (f <= static_cast<float>(INT_MAX) && f >= static_cast<float>(INT_MIN))
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}
void ScalarConverter::handle_double(double d)
{
	int i = static_cast<int>(d);

	if (d < 0 || d > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(i))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;

	if (d <= INT_MAX && d >= INT_MIN)
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: impossible" << std::endl;

	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
	std::cout << std::fixed << std::setprecision(1);
	type t = detect_type(literal);
	switch (t)
	{
		case NNAN:
		case INF_P:
		case INF_M:
			handle_special_literals(t);
			break;
		case CHAR:
			handle_char(literal[0]);
			break;
		case INT:
		{
			char *end;
			long value = std::strtol(literal.c_str(), &end, 10);
			if(*end != '\0')
			{
				std::cout << "Invalid literal!" << std::endl;
				break;
			}
			if (value > INT_MAX || value < INT_MIN)
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: impossible" << std::endl;
				break;
			}
			handle_int(static_cast<int>(value));
			break;
		}
		case FLOAT:
			handle_float(std::atof(literal.c_str()));
			break;
		case DOUBLE:
		{
			char *end;
			handle_double(std::strtod(literal.c_str(), &end));
			break;
		}
		default:
			std::cout << "Invalid literal!" << std::endl;
	}
}
