#include <iostream>
#include <string>
#include <memory>
#include "DLLoader.h"
#include "IPlanet.h"

using namespace std;

#ifdef WIN32
static const std::string bespinLibPath = "BespinLib.dll";
static const std::string tatooineLibPath = "TatooineLib.dll";
#endif
#ifdef __linux__
static const std::string bespinLibPath = "lib_bespin.so";
static const std::string tatooineLibPath = "lib_tatooine.so";
#endif

/*
** Using the smart pointer directly in an inner function because
** the reference to its destructor contained in the dll is lost before
** going out of the caller function's scope.
*/
void greetFromAPlanet(dlloader::DLLoader<IPlanet>& dlloader)
{
	std::shared_ptr<IPlanet> planet = dlloader.DLGetInstance();

	planet->greet();
}

void greet(const std::string& path)
{
	dlloader::DLLoader<IPlanet> dlloader(path);

	std::cout << "Loading " << path << std::endl;
	dlloader.DLOpenLib();

	greetFromAPlanet(dlloader);

	std::cout << "Unloading " << path << std::endl;
	dlloader.DLCloseLib();
}

int main()
{
	greet(tatooineLibPath);
	greet(bespinLibPath);

	return 0;
}