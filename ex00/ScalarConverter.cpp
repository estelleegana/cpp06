#include "ScalarConverter.hpp"

literaltype ScalarConverter::detectType(std::string &str)
{
	if (str.size() > 0)
	{
		if (str.size() == 1 && !std::isdigit(str[0]))
			return typechar;

		//signe?
		unsigned int a = 0;
		if (str[0] == '+' || str[0] == '-')
			a++;
		
		size_t pos_virgule = str.find('.');
		//sans virgule
		if (pos_virgule == std::string::npos)
		{
			for (size_t i = 0 + a; i < str.size(); i++)
			{
				if (!std::isdigit(str[i]))
					return typeinvalid;
			}
			return typeint;//INT
		}
		else//virgule
		{
			if (pos_virgule == str.rfind('.'))//une seule virgule
			{
				if (str[str.size() - 1] == 'f')
				{
					if (str.find('f') == str.rfind('f'))//un seul 'f'
						return typefloat;//FLOAT
					else
						return typeinvalid;
				}
				else
				{
					for (size_t j = 0 + a; j < str.size(); j++)
					{
						if (std::isalpha(str[j]))
							return typeinvalid;
					}
					return typedouble;
				}
			}
		}
	}
	return typeinvalid;
}

static void ScalarConverter::convert(std::string &literal)
{

}