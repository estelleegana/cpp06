#pragma once

#include <string>
#include <iostream>//std::cout
#include <cctype>//isalpha
#include <sstream>//ss
#include <cstdlib>//atoi, atol, atof
#include <climits>//INT_MIN et INT_MAX (overflow)
#include <stdexcept>//std::invalid_argument et std::overflow_error

enum literaltype
{
	TYPECHAR,//0
	TYPEINT,//1
	TYPEFLOAT,//2
	TYPEDOUBLE,//3
	TYPEINVALID//4
};

class ScalarConverter
{	
	private://constr en prive = classe non-instanciable
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &autre);
		~ScalarConverter();
	public:
		static void convert(std::string &literal);


};

literaltype detectType(std::string &literal);
void print_literaltype(literaltype lt);
void fromChar(std::string &literal);
void fromInt(std::string &literal);
void fromFloat(std::string &literal);
void fromDouble(std::string &literal);
void fromPseudoFloat(std::string &literal);
void fromPseudoDouble(std::string &literal);
