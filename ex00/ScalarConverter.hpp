/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 01:41:44 by gshekari          #+#    #+#             */
/*   Updated: 2026/07/07 09:04:10 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <ctype.h>

class ScalarConverter
{
	private:
	   enum type
		{
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			INVALID
		};
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter&operator=(const ScalarConverter &other);
		~ScalarConverter();
		static type detect_type(std::string &literal);
	public:
		static void convert(std::string &literal);
};

#endif
