#include "Base.hpp"

int main()
{
	Base *bbb = generate();

	identify(bbb);
	identify(*bbb);

	delete bbb;
	return 0;
}