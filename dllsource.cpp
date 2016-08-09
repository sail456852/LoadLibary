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


//extern "C"  before any exporting function from dll is a must , during my test , I found that if I remove the extern "C" keyword 
//They both will be compiled successfully , but when executing , the calling process (aka exe which uses the function pointer) will fail 
// to find the function address in that dll instance , why , maybe because the supposed to be exported function , is not accessible from 
//another instance aka , the calling process 


//I tried with the extern keyword only , omitted "C" , which I supposed to mean this is C++ style extern function , not C style 
//but why it crashed again , aha ? I don't know ,by far it means you have to prefix extern "C" before any function you wanna 
//export into another process . 


//the C++ compiler does not add argument/parameter type information to the name used for linkage.
//That's what the explanation is , on stackoverflow .

//extern "C" is a linkage-specification
//Every compiler is required to provide "C" linkage
