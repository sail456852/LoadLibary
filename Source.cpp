
#include <iostream>
#include <Windows.h>
#include <tchar.h>

typedef int(__stdcall *p_myfunc)();

int main()
{
	HINSTANCE hGetProcIDDLL = LoadLibrary(TEXT("C:\\Users\\ff\\Documents\\Visual Studio 2015\\Projects\\test\\x64\\Debug\\dll.dll"));

	if (!hGetProcIDDLL) {
		std::cout << "could not load the dynamic library" << std::endl;
		return EXIT_FAILURE;
	}


	p_myfunc myfunction = (p_myfunc)GetProcAddress(hGetProcIDDLL, "myfunction");

	if (!myfunction)
	{
		std::cout << "could not locate the function" << std::endl;
		return EXIT_FAILURE;
	}

	std::cout << "funci() returned " << myfunction() << std::endl;

	return EXIT_SUCCESS;
}