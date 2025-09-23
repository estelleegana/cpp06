#pragma once

#include <string>
#include <iostream>//std::cout
#include <cctype>//isalpha
#include <sstream>//ss
#include <cstdlib>	//atoi

enum literaltype
{
	typechar,//0
	typeint,//1
	typefloat,//2
	typedouble,//3
	typeinvalid//4
};

class ScalarConverter
{
	public:
		static void convert(std::string &literal);

};

literaltype detectType(std::string &literal);
void fromChar(std::string &literal);
void fromInt(std::string &literal);
void fromFloat(std::string &literal);
void fromDouble(std::string &literal);
float strToFloat(const std::string &literal);