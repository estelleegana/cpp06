#pragma once

#include <string>
#include <iostream>//std::cout
#include <cctype>//isalpha
#include <sstream>//ss

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
void toChar(std::string &literal);
void toInt(std::string &literal);
void toFloat(std::string &literal);
void toDouble(std::string &literal);
int strToInt(const std::string &literal);
float strToFloat(const std::string &literal);