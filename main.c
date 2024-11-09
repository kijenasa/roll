#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define d20art \
 "       _-_.\n" \
 "    _-',^. `-_.\n" \
 "._-' ,'   `.   `-_ \n" \
 "!`-_._________`-':::\n" \
 "!   /\\        /\\::::\n" \
 ";  /  \\  \e[1m%02d\e[0m  /..\\:::\n" \
 "! /    \\    /....\\::\n" \
 "!/      \\  /......\\:\n" \
 ";--.___. \\/_.__.--;; \n" \
 " '-_    `:!;;;;;;;'\n" \
 "    `-_, :!;;;''\n" \
 "        `-!'\n"

#define d12art \
 "    _,--\"^\"--._\n" \
 "  ,'\\         /`.\n" \
 ",'   \\_______/   `.\n" \
 "|     /       \\     |\n" \
 "|    /         \\    |\n" \
 "|  _/    \e[1m%02d\e[0m     \\_  |\n" \
 "\\'' `-.       ,-' ``/\n" \
 " \\     `-._,-'     /\n" \
 "  \\       |       /\n" \
 "   `-.._  |  _,,-'\n" \
 "        ``\"''\n"

#define d10art \
  "    ,'.\n" \
  "  ,'   `.\n" \
  ",'_______`.\n" \
  "\\   \e[1m%02d\e[0m    / \n" \
  " \\       /\n" \
  "  \\_____/ \n"

#define d8art \
    "    /\\\n" \
    "   /  \\\n" \
    "  / \e[1m%02d\e[0m \\\n" \
    " /______\\\n" \
    "  \\    /\n" \
    "   \\  /\n" \
    "    \\/\n"

#define d6art \
    "│‾‾‾‾‾‾‾‾│\n" \
    "│   \e[1m%02d\e[0m   │\n" \
    "│        │\n" \
    "│________│\n"

#define d4art \
 "      /\\\n" \
 "     /  \\\n" \
 "    / \e[1m%02d\e[0m \\\n" \
 "   /      \\\n" \
 "  /________\\\n"

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
	printf(d12art, value);
	printf(d10art, value);
	printf(d8art, value);
	printf(d6art, value);
	printf(d4art, value);
}
