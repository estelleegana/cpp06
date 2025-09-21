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
	toChar(literal);
	toInt(literal);
	toFloat(literal);
	toDouble(literal);
}

void toChar(std::string &literal)
{
	if (detectType(literal) == typechar)
		std::cout << literal << " char: " << literal[0] << std::endl;
	else if (detectType(literal) == typeint)
	{
		if (isprint(strToInt(literal)) == false)
			std::cout << literal << " char: " << "non displayable" << std::endl;
		else
		{
			char c = strToInt(literal);
			std::cout << literal << " char: '" << c << "'" << std::endl;
		}
	}
	else if ((detectType(literal) == typefloat))
	{
		if (isprint(strToFloat(literal)) == false)
			std::cout << literal << " char: " << "non displayable" << std::endl;
		else
		{
			char c = strToFloat(literal);
			std::cout << literal << " char: '" << c << "'" << std::endl;
		}
	}
}

void toInt(std::string &literal)
{
	if (detectType(literal) == typechar)
		std::cout << literal << " int: " << static_cast<int>(literal[0]) << std::endl;
	else if (detectType(literal) == typeint)
		std::cout << literal << " int: " << strToInt(literal) << std::endl;
	else if ((detectType(literal) == typefloat))
		std::cout << literal << " int: " << strToFloat(literal) << std::endl;
}

void toFloat(std::string &literal)
{
	if (detectType(literal) == typechar)
		std::cout << literal << " float: " << static_cast<float>(literal[0]) << ".0f" << std::endl;
	else if (detectType(literal) == typeint)
		std::cout << literal << " float: " << strToInt(literal) << ".0f" << std::endl;
}

void toDouble(std::string &literal)
{
	if (detectType(literal) == typechar)
		std::cout << literal << " double: " << static_cast<double>(literal[0]) << ".0" << std::endl;
	else if (detectType(literal) == typeint)
		std::cout << literal << " double: " << strToInt(literal) << ".0" << std::endl;
}

int strToInt(const std::string &literal)
{
    std::stringstream ss(literal);
    int value = 0;
    ss >> value;
    if (ss.fail() || !ss.eof()) {  // si conversion échoue ou reste du texte
        std::cerr << "strToInt fail" << std::endl;
        return 0; // ou une valeur spéciale
    }
    return value;
}

float strToFloat(const std::string &literal)
{
	std::string s = literal;
	s = s.substr(0, s.length() - 1);
    std::stringstream ss(s);
    float value = 0.0f;
    ss >> value;
    if (ss.fail() || !ss.eof()) {  // si conversion échoue ou reste du texte
        std::cerr << "strToFloat fail" << std::endl;
        return 0.0f; // ou une valeur spéciale
    }
    return value;
}