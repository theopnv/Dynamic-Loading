#include "Bespin.h"

#ifdef __linux__
extern "C"
{
	Bespin *allocator()
	{
		return new Bespin();
	}

	void deleter(Bespin *ptr)
	{
		delete ptr;
	}
}
#endif

#ifdef WIN32
extern "C"
{
	__declspec (dllexport) Bespin *allocator()
	{
		return new Bespin();
	}

	__declspec (dllexport) void deleter(Bespin *ptr)
	{
		delete ptr;
	}
}
#endif

void Bespin::greet()
{
	std::cout << "Greetings from Bespin !" << std::endl;
}