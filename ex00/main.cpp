#include "ScalarConverter.hpp"

int main()
{
	std::string literal;
	literaltype type;

	std::cout << "----------- CHAR (0)" << std::endl;
	literal = "a";
	type = ScalarConverter::detectType(literal);
	std::cout << type << std::endl;
	literal = ".";
	type = ScalarConverter::detectType(literal);
	std::cout << type << std::endl;

	std::cout << "----------- INT (1)" << std::endl;
	literal = "42";
	type = ScalarConverter::detectType(literal);
	std::cout << type << std::endl;
	literal = "+42";
	type = ScalarConverter::detectType(literal);
	std::cout << type << std::endl;
	literal = "-42";
	type = ScalarConverter::detectType(literal);
	std::cout << type << std::endl;
	literal = "000";
	type = ScalarConverter::detectType(literal);
	std::cout << type << std::endl;

	std::cout << "----------- FLOAT (2)" << std::endl;
	literal = "42.42f";
	type = ScalarConverter::detectType(literal);
	std::cout << type << std::endl;
	literal = "+42.42f";
	type = ScalarConverter::detectType(literal);
	std::cout << type << std::endl;

	std::cout << "----------- DOUBLE (3)" << std::endl;
	literal = "42.42";
	type = ScalarConverter::detectType(literal);
	std::cout << type << std::endl;
	literal = "+42.42";
	type = ScalarConverter::detectType(literal);
	std::cout << type << std::endl;

	std::cout << "----------- INVALID (4)" << std::endl;
	literal = "exemple";
	type = ScalarConverter::detectType(literal);
	std::cout << type << std::endl;
	literal = "";
	type = ScalarConverter::detectType(literal);
	std::cout << type << std::endl;
	literal = "=42";
	type = ScalarConverter::detectType(literal);
	std::cout << type << std::endl;
	literal = "42..42";
	type = ScalarConverter::detectType(literal);
	std::cout << type << std::endl;
	literal = "42..42f";
	type = ScalarConverter::detectType(literal);
	std::cout << type << std::endl;
	literal = "42.42ff";
	type = ScalarConverter::detectType(literal);
	std::cout << type << std::endl;
	literal = "4242f";
	type = ScalarConverter::detectType(literal);
	std::cout << type << std::endl;
	literal = "aa.aa";
	type = ScalarConverter::detectType(literal);
	std::cout << type << std::endl;
}