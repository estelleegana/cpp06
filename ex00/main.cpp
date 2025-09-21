#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		std::string literal;
		literaltype type;

		literal = argv[1];
		type = detectType(literal);
		ScalarConverter::convert(literal);
		std::cout << type << std::endl;
	}
}