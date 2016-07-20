#include <iostream>

//dll function ready to be exported

extern "C" int __declspec(dllexport) __stdcall  myfunction()  //without extern "C" ,this function won't be located from the host application
{
	std::cout << "I am being called from the dll dynamically!";
	return 1;
}
