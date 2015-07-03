#include "myfactory.h"

#include <stdio.h>
#include <stdlib.h>

typedef char const* (*PTRFUN)();

struct Animal{
	PTRFUN* vtable;
};

void animalPrintGreeting(struct Animal* this) {
	printf("%s greets: %s\n", this->vtable[0](this), this->vtable[1]());
}

void animalPrintMenu(struct Animal* this) {
	printf("%s loves: %s\n", this->vtable[0](this), this->vtable[2]());
}

// parrots and tigers defined in respective dynamic libraries

// animalPrintGreeting and animalPrintMenu similar as in lab 1

int main(void){
	struct Animal* p1=(struct Animal*)myfactory("parrot", "Modrobradi");
	struct Animal* p2=(struct Animal*)myfactory("tiger", "Straško");
	if (!p1 || !p2){
		printf("Creation of plug-in objects failed.\n");
		exit(1);
	}

	animalPrintGreeting(p1); //"Sto mu gromova!"
	animalPrintGreeting(p2); //"Mijau!"

	animalPrintMenu(p1); //"brazilske orahe"
	animalPrintMenu(p2); //"mlako mlijeko"

	free(p1); free(p2);
	
	return 0;  
}