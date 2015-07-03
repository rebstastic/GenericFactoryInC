#include <stdlib.h>

typedef char const* (*funptr)();

typedef struct {
	funptr* vtable;
	char const* name;
} Tiger;

char const* name(void* this) {
	return ((Tiger*)this)->name;
}

char const* greet(void){
  return "Mijau!";
}

char const* menu(void){
  return "mlako mlijeko";
}

funptr TigerVTable[3] = {
	name,
	greet,
	menu
};

void TigerInit(Tiger* this, char const* name) {
	this->vtable = TigerVTable;
	this->name = name;
}

void* create(char const* name) {
	Tiger* tiger = (Tiger*)malloc(sizeof(Tiger));
	TigerInit(tiger, name);
	return tiger;
}