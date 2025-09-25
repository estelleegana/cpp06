#pragma once

#include <string>

struct Data
{
	int id;
	std::string name;
	double value;

	Data();
	Data(const int &i, const std::string &n, const double &v);
};