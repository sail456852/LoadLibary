#include <iostream>

//dll function ready to be exported

extern "C" int __declspec(dllexport) __stdcall  myfunction()  //without extern "C" ,this function won't be located from the host application
{
	std::cout << "I am being called from the dll dynamically!";
	return 1;
}

//During my test , I found that there is no need to add __stdcall , and there is no need to add __declspec(dllexport) before a function 
//definition , if you can do  that before the function declaration in the corresponding header file , :P 

//and also there is no need to use the header file ,but you can use it , it doesn't really matter , if you just wanna call a function in that
//dll , why ? because calling the function in that dll from exe process , is done indirectly ,through function pointer . you can't 
//call that function directly through the function name , because that name is in another namespace . 
