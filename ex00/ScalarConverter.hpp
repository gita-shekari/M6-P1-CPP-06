/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 01:41:44 by gshekari          #+#    #+#             */
/*   Updated: 2026/07/08 03:50:13 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <climits>
#include <cstdlib>
#include <iomanip>

class ScalarConverter
{
	private:
	   enum type
		{
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			INF_P,
			INF_M,
			NNAN,
			INVALID
		};
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter&operator=(const ScalarConverter &other);
		~ScalarConverter();
		static type detect_type(const std::string &literal);
		static void handle_special_literals(type t);
		static void handle_char(char c);
		static void handle_int(int i);
		static void handle_float(float f);
		static void handle_double(double d);
	public:
		static void convert(const std::string &literal);
};

#endif
