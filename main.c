#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ASCII "        _-_.\n     _-',^. `-_.\n ._-' ,'   `.   `-_\n!`-_._________`-':::\n!   /\\        /\::::\n;  /  \\  %02d  /..\:::\n! /    \\    /....\\::\n!/      \\  /......\\:\n;--.___. \\/_.__.--;;\n '-_    `:!;;;;;;;'\n    `-_, :!;;;''\n        `-!'\n"

int roll(int size) {
	int num = 1 + rand() % (size - 1);
	return num;
}

int main() {
	srand(clock());
	int value = roll(20);
	printf(ASCII, value);
}
