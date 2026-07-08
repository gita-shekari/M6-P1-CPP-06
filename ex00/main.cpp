/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:04:59 by gshekari          #+#    #+#             */
/*   Updated: 2026/07/08 03:41:57 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main()
{
	std::cout << "\n--- Testing char ---\n";
	ScalarConverter::convert("h");
	std::cout << "\n--- Testing int ---\n";
	ScalarConverter::convert("42");
	std::cout << "\n--- Testing float ---\n";
	ScalarConverter::convert("42.0f");
	std::cout << "\n--- Testing double---\n";
	ScalarConverter::convert("42.0");
	std::cout << "\n--- Testing nan---\n";
	ScalarConverter::convert("nan");
	std::cout << "\n--- Testing +inf---\n";
	ScalarConverter::convert("+inf");
	std::cout << "\n--- Testing -inf---\n";
	ScalarConverter::convert("-inf");
	std::cout << "\n--- Testing 0 ---\n";
	ScalarConverter::convert("0");
	std::cout << "\n--- Testing large number ---\n";
	ScalarConverter::convert("999999999999999999999");
	std::cout << "\n--- Testing MAX INT ---\n";
	ScalarConverter::convert("2147483647");
	std::cout << "\n--- Testing MAX INT ---\n";
	ScalarConverter::convert("-2147483646");
	std::cout << "\n--- Testing printable char (65) ---\n";
	ScalarConverter::convert("65");
	std::cout << "\n--- Testing non-printable char (31) ---\n";
	ScalarConverter::convert("31");
	std::cout << "\n--- Testing first printable char (32) ---\n";
	ScalarConverter::convert("32");
	std::cout << "\n--- Testing DEL character (127) ---\n";
	ScalarConverter::convert("127");
	std::cout << "\n--- Testing char overflow (128) ---\n";
	ScalarConverter::convert("128");
	std::cout << "\n--- Testing negative int ---\n";
	ScalarConverter::convert("-42");
	std::cout << "\n--- Testing positive sign ---\n";
	ScalarConverter::convert("+42");
	std::cout << "\n--- Testing negative float ---\n";
	ScalarConverter::convert("-42.5f");
	std::cout << "\n--- Testing positive double ---\n";
	ScalarConverter::convert("+42.5");
	std::cout << "\n--- Testing zero float ---\n";
	ScalarConverter::convert("0.0f");
	std::cout << "\n--- Testing zero double ---\n";
	ScalarConverter::convert("0.0");
	std::cout << "\n--- Testing invalid (letters) ---\n";
	ScalarConverter::convert("abc");
	std::cout << "\n--- Testing invalid (double dot) ---\n";
	ScalarConverter::convert("4..2");
	std::cout << "\n--- Testing invalid (only dot) ---\n";
	ScalarConverter::convert(".");
	std::cout << "\n--- Testing invalid (missing digits) ---\n";
	ScalarConverter::convert("+");
	std::cout << "\n--- Testing invalid (only minus) ---\n";
	ScalarConverter::convert("-");
	std::cout << "\n--- Testing invalid float suffix ---\n";
	ScalarConverter::convert("42f");
	std::cout << "\n--- Testing empty string ---\n";
	ScalarConverter::convert("");
	std::cout << "\n--- more tests---\n";
	ScalarConverter::convert("126.5");
	ScalarConverter::convert("128");
	ScalarConverter::convert("-128");
	ScalarConverter::convert("-129");
	ScalarConverter::convert("2147483648");
	ScalarConverter::convert("-2147483649");
	ScalarConverter::convert("0042");
	ScalarConverter::convert("-0");
	ScalarConverter::convert("+0");
		return 0;

}
