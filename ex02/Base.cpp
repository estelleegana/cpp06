#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
	std::cout << "\033[38;2;255;0;0mDestructor Base\033[0m" << std::endl;
}

Base *Base::generate(void)
{
	static int counter = 0;//compteur static pour varier
	time_t t = time(NULL);//melanger ac l'heure
	int choice = (counter++ + t) % 3;

	switch (choice)//test 1 variable (choice) contre 3 valeurs
	{
		case 0:
			return new A();
		case 1:
			return new B();
		default:
			return new C();
	}
}