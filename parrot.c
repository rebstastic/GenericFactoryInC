#include <stdlib.h>

typedef char const* (*funptr)();

typedef struct {
	funptr* vtable;
	char const* name;
} Parrot;

char const* name(void* this) {
	return ((Parrot*)this)->name;
}

char const* greet(void){
  return "Sto mu gromova!";
}

char const* menu(void){
  return "brazilske orahe";
}

funptr ParrotVTable[3] = {
	name,
	greet,
	menu
};

void ParrotInit(Parrot *this, char const* name) {
	this->vtable = ParrotVTable;
	this->name = name;
}

void* create(char const* name) {
	Parrot* parrot = (Parrot*)malloc(sizeof(Parrot));
	ParrotInit(parrot, name);
	return parrot;
}