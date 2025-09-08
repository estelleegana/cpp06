#pragma once

#include <string>
#include <iostream>//std::cout
#include <cctype>//isalpha

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
		static literaltype detectType(std::string &str);
		static void convert(std::string &literal);
};