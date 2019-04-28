#include "Tatooine.h"

#if defined(__linux__) || defined(__APPLE__)
extern "C"
{
	Tatooine *allocator()
	{
		return new Tatooine();
	}

	void deleter(Tatooine *ptr)
	{
		delete ptr;
	}
}
#endif

#ifdef WIN32
extern "C"
{
	__declspec (dllexport) Tatooine *allocator()
	{
		return new Tatooine();
	}

	__declspec (dllexport) void deleter(Tatooine *ptr)
	{
		delete ptr;
	}
}
#endif

void Tatooine::greet()
{
	std::cout << "Greetings from Tatooine !" << std::endl;
}