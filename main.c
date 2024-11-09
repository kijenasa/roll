#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define d20art "        _-_.\n     _-',^. `-_.\n ._-' ,'   `.   `-_\n!`-_._________`-':::\n!   /\\        /\::::\n;  /  \\  %02d  /..\:::\n! /    \\    /....\\::\n!/      \\  /......\\:\n;--.___. \\/_.__.--;;\n '-_    `:!;;;;;;;'\n    `-_, :!;;;''\n        `-!'\n"

int roll(int size) {
	int num = (rand() % size) + 1;
	return num;
}

int main(int argc, char* argv[]) {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	long milliseconds = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	srand(milliseconds);

	int value = roll(20);
	printf(d20art, value);
}
