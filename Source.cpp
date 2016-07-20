
#include <iostream>
#include <Windows.h>
#include <tchar.h>
//revised from stackoverflow example 
typedef int(__stdcall *p_myfunc)();  //function pointer type for the function to be called inside the dynamical library 

int main()
{
	HINSTANCE hGetProcIDDLL = LoadLibrary(TEXT("C:\\Users\\ff\\Documents\\Visual Studio 2015\\Projects\\test\\x64\\Debug\\dll.dll"));

	if (!hGetProcIDDLL) {   //check if the loadlibrary succeeded ?
		std::cout << "could not load the dynamic library" << std::endl;
		return EXIT_FAILURE;
	}

         //myfunction1 can be any name you want , but the "myfunction" has to be the name of the function you wish to call inside the dll 
	p_myfunc myfunction1 = (p_myfunc)GetProcAddress(hGetProcIDDLL, "myfunction");  
        //see if this API can find the target function inside the dll by using the suitable function pointer we just created . 
	if (!myfunction1) //check if this function pointer contains something useful 
	{
		std::cout << "could not locate the function" << std::endl;
		return EXIT_FAILURE;
	}

	std::cout << "funci() returned " << myfunction1() << std::endl;  //remember here you call using the new function pointer not the original function name 

	return EXIT_SUCCESS;
}
