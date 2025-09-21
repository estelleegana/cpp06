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
	char c;

	c = 'o';
	std::cout << literal << " to char: " << c << std::endl;
}

void toInt(std::string &literal)
{
	int x;

	x = 42;
	std::cout << literal << " to int: " << x << std::endl;
}

void toFloat(std::string &literal)
{
	float f;

	f = 42.42f;
	std::cout << literal << " to float: " << f << std::endl;
}

void toDouble(std::string &literal)
{
	double d;

	d = 42.4242;
	std::cout << literal << " to double: " << d << std::endl;
}
