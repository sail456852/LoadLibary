#include <iostream>

//dll function ready to be exported

extern "C" int __declspec(dllexport) __stdcall  myfunction()
{
	std::cout << "I am being called from the dll dynamically!";
	return 1;
}