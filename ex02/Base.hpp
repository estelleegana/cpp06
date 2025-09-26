#pragma once

#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

class Base
{
	public:
		virtual ~Base();
		
};

Base *generate(void);