#include "ScalarConverter.hpp"

literaltype detectType(std::string &literal)
{
	if (literal.size() > 0)
	{
		if (literal.size() == 1 && !std::isdigit(literal[0]))
			return typechar;

		//signe?
		unsigned int a = 0;
		if (literal[0] == '+' || literal[0] == '-')
			a++;
		
		size_t pos_virgule = literal.find('.');
		//sans virgule
		if (pos_virgule == std::string::npos)
		{
			for (size_t i = 0 + a; i < literal.size(); i++)
			{
				if (!std::isdigit(literal[i]))
					return typeinvalid;
			}
			return typeint;//INT
		}
		else//virgule
		{
			if (pos_virgule == literal.rfind('.'))//une seule virgule
			{
				if (literal[literal.size() - 1] == 'f')
				{
					if (literal.find('f') == literal.rfind('f'))//un seul 'f'
						return typefloat;//FLOAT
					else
						return typeinvalid;
				}
				else
				{
					for (size_t j = 0 + a; j < literal.size(); j++)
					{
						if (std::isalpha(literal[j]))
							return typeinvalid;
					}
					return typedouble;
				}
			}
		}
	}
	return typeinvalid;
}

void ScalarConverter::convert(std::string &literal)
{
	if (detectType(literal) == typechar)
		fromChar(literal);
	else if (detectType(literal) == typeint)
		fromInt(literal);
	else if ((detectType(literal) == typefloat))
		fromFloat(literal);
	else if ((detectType(literal) == typedouble))
		fromDouble(literal);
}

void fromChar(std::string &literal)
{

	std::cout << literal << " char: " << literal[0] << std::endl;
	std::cout << literal << " int: " << static_cast<int>(literal[0]) << std::endl;
	std::cout << literal << " float: " << static_cast<float>(literal[0]) << ".0f" << std::endl;
	std::cout << literal << " double: " << static_cast<double>(literal[0]) << ".0" << std::endl;
}

void fromInt(std::string &literal)
{
	if (isprint(atoi(literal.c_str())) == false)
		std::cout << literal << " char: " << "non displayable" << std::endl;
	else
		std::cout << literal << " char: '" << static_cast<char>(atoi(literal.c_str())) << "'" << std::endl;
	std::cout << literal << " int: " << atoi(literal.c_str()) << std::endl;
	std::cout << literal << " float: " << static_cast<float>(atoi(literal.c_str())) << ".0f" << std::endl;
	std::cout << literal << " double: " << static_cast<double>(atoi(literal.c_str())) << ".0" << std::endl;
}

void fromFloat(std::string &literal)
{
	if (isprint(atoi(literal.c_str())) == false)
		std::cout << literal << " char: " << "non displayable" << std::endl;
	else
		std::cout << literal << " char: '" << static_cast<char>(atoi(literal.c_str())) << "'" << std::endl;// 	if (detectType(literal) == typechar)
	std::cout << literal << " int: " << atoi(literal.c_str()) << std::endl;
	std::cout << literal << " float: " << static_cast<float>(strToFloat(literal)) << std::endl;
	std::cout << literal << " double: " << strtod(literal.c_str(), NULL) << std::endl;
}

void fromDouble(std::string &literal)
{
	if (isprint(atoi(literal.c_str())) == false)
		std::cout << literal << " char: " << "non displayable" << std::endl;
	else
		std::cout << literal << " char: '" << static_cast<char>(atoi(literal.c_str())) << "'" << std::endl;// 	if (detectType(literal) == typechar)
	std::cout << literal << " int: " << atoi(literal.c_str()) << std::endl;
	std::cout << literal << " float: " << static_cast<float>(atof(literal.c_str())) << std::endl;
	std::cout << literal << " double: " << strtod(literal.c_str(), NULL) << std::endl;
}



float strToFloat(const std::string &literal)
{
    std::stringstream ss(literal);
    float value = 0.0f;
    ss >> value;
    if (ss.fail() || !ss.eof()) {
        std::cerr << "Erreur: conversion float échouée" << std::endl;
        return 0.0f;
    }
    return value;
}