#include <iostream>

#include "Pony.class.hpp"

void ponyOnTheHeap(void) {
	Pony* heapPony = new Pony("Heap Pony");
	delete heapPony;
}

void ponyOnTheStack(void) {
	Pony stackPony = Pony("Stack Pony");
}

int main(void) {

	ponyOnTheHeap();
	ponyOnTheStack();

	return 0;
}