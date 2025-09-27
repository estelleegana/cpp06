#include "Base.hpp"

Base::~Base()
{
	std::cout << "\033[1;31mDestructor Base\033[0m" << std::endl;
}

Base *generate(void)
{
	static int counter = 0;//compteur static pour varier
	time_t t = time(NULL);//melanger ac l'heure
	int choice = (counter++ + t) % 3;

	switch (choice)//test 1 variable (choice) contre 3 valeurs
	{
		case 0:
			std::cout << "\033[32mA class\033[0m" << std::endl;
			return new A();
		case 1:
			std::cout << "\033[32mB class\033[0m" << std::endl;
			return new B();
		default:
			std::cout << "\033[32mC class\033[0m" << std::endl;
			return new C();
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))//si p pointe vers un A
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
	identify(&p);
}