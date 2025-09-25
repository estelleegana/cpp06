#include "ScalarConverter.hpp"

literaltype detectType(std::string &literal)
{
	//char
	if (literal.size() == 1 && isprint(literal[0]) && !std::isdigit(literal[0]))
		return TYPECHAR;

	//pseudo-literals
	if (literal == "nan" || literal == "+inf" || literal == "-inf") {
    	return TYPEDOUBLE; }
    if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
    	return TYPEFLOAT; }

	//signe?
	unsigned int a = 0;
	if (literal[0] == '+' || literal[0] == '-')
		a++;
	
	size_t pos_virgule = literal.find('.');
	if (pos_virgule == std::string::npos)//sans virgule
	{
		for (size_t i = 0 + a; i < literal.size(); i++)
		{
			if (!std::isdigit(literal[i]))
				return TYPEINVALID;
		}
		if (atol(literal.c_str()) < INT_MIN || atol(literal.c_str()) > INT_MAX)
		{
			std::cerr << "int overflow" << std::endl;
			return TYPEINVALID;
		}
		return TYPEINT;//INT
	}
	else//avec virgule
	{
		if (pos_virgule == literal.rfind('.'))//une seule virgule
		{
			if (literal[literal.size() - 1] == 'f')
			{
				if (literal.find('f') == literal.rfind('f'))//un seul 'f'
				{
					if (atof(literal.c_str()) < INT_MIN || atof(literal.c_str()) > INT_MAX)
					{
						std::cerr << "float overflow" << std::endl;
						return TYPEINVALID;
					}
					return TYPEFLOAT;//FLOAT
				}
				else
					return TYPEINVALID;
			}
			else
			{
				for (size_t j = 0 + a; j < literal.size(); j++)
				{
					if (std::isalpha(literal[j]))
						return TYPEINVALID;
				}
				if (strtod(literal.c_str(), NULL) < INT_MIN || strtod(literal.c_str(), NULL) > INT_MAX)
				{
					std::cerr << "double overflow" << std::endl;
					return TYPEINVALID;
				}
				return TYPEDOUBLE;
			}
		}
	}
	return TYPEINVALID;
}

//switch car on teste 1 variable (ici type) contre plusieurs valeurs
void ScalarConverter::convert(std::string &literal)
{
	literaltype type = detectType(literal);

	// std::cout << "literal : " << "\033[1;34m" << literal << "\033[0m" << std::endl << "type : ";
	print_literaltype(type);
	std::cout << std::endl << std::endl;
	switch (type)
	{
		case TYPECHAR:
			fromChar(literal);
			break;
		case TYPEINT:
			fromInt(literal);
			break;
		case TYPEFLOAT:
			fromFloat(literal);
			break;
		case TYPEDOUBLE:
			fromDouble(literal);
			break;
		case TYPEINVALID:
			break;
		default:
			break;
	}
}

void print_literaltype(literaltype lt)
{
	switch (lt)
	{
		case TYPECHAR:
			std::cout << "\033[1;32mchar\033[0m";
			break;
		case TYPEINT:
			std::cout << "\033[1;32mint\033[0m";;
			break;
		case TYPEFLOAT:
			std::cout << "\033[1;32mfloat\033[0m";;
			break;
		case TYPEDOUBLE:
			std::cout << "\033[1;32mdouble\033[0m";;
			break;
		case TYPEINVALID:
			std::cerr << "\033[1;31minvalid type\033[0m";
			break;
		default:
			std::cerr << "\033[1;31minvalid type\033[0m";
	}
}

void fromChar(std::string &literal)
{
	std::cout << "char: '" << literal[0] << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(literal[0]) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(literal[0]) << ".0" << std::endl;
}

void fromInt(std::string &literal)
{
	int val_int = atol(literal.c_str());

	if (isprint(val_int) == false)
		std::cout << "char: " << "non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(val_int) << "'" << std::endl;
	std::cout << "int: " << val_int << std::endl;
	std::cout << "float: " << static_cast<float>(val_int) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(val_int) << ".0" << std::endl;
}

void fromFloat(std::string &literal)
{
    if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
    	fromPseudoFloat(literal); }
	else
	{
		float val_float = atof(literal.c_str());

	if (isprint(val_float) == false)
		std::cout << "char: " << "non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(val_float) << "'" << std::endl;// 	if (detectType(literal) == TYPECHAR)
	std::cout << "int: " << static_cast<int>(val_float) << std::endl;
	std::cout << "float: " << val_float << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(val_float) << std::endl;
	}
}

void fromDouble(std::string &literal)
{
	if (literal == "nan" || literal == "+inf" || literal == "-inf") {
    	fromPseudoDouble(literal); }
	else
	{
		double val_double = strtod(literal.c_str(), NULL);

	if (isprint(val_double) == false)
		std::cout << "char: " << "non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(val_double) << "'" << std::endl;// 	if (detectType(literal) == TYPECHAR)
	std::cout << "int: " << static_cast<int>(val_double) << std::endl;
	std::cout << "float: " << static_cast<float>(val_double) << "f" << std::endl;
	std::cout << "double: " << val_double << std::endl;
	}
}

void fromPseudoDouble(std::string &literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << literal << "f" << std::endl;
	std::cout << "double: " << literal << std::endl;

}

void fromPseudoFloat(std::string &literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << literal << std::endl;
	std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;

}

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=( const ScalarConverter &autre )
{
	(void)autre;
    return (*this);
}

ScalarConverter::~ScalarConverter() {}