#include "myfactory.h"

#include<windows.h>
#include <stdio.h>

typedef void* (*funptr)(char const*);

void* myfactory(char const* animalType, char const* animalName) {

	// Concat full path to animal type string.
	char str[50];
	strcpy(str, "./");
	strcat(str, animalType);
	strcat(str, ".dll");
	animalType = str;

	// Load library.
	HINSTANCE dllHandle = LoadLibrary(animalType);
	if(!dllHandle) {
		printf("Unable to load library.\n");
		return;
	}
	
	// Resolve function address.
	funptr fun;
	fun = (funptr) GetProcAddress(dllHandle, "create");
	if(!fun) {
		FreeLibrary(dllHandle);
		printf("Unable to load function.\n");
		return;
	}
	
	// Call the function.
	return fun(animalName);
}