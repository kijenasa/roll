#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define D20_ART \
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

#define D12_ART \
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

#define D10_ART \
  "    ,'.\n" \
  "  ,'   `.\n" \
  ",'_______`.\n" \
  "\\   \e[1m%02d\e[0m    / \n" \
  " \\       /\n" \
  "  \\_____/ \n"

#define D8_ART \
    "    /\\\n" \
    "   /  \\\n" \
    "  / \e[1m%02d\e[0m \\\n" \
    " /______\\\n" \
    "  \\    /\n" \
    "   \\  /\n" \
    "    \\/\n"

#define D6_ART \
    "│‾‾‾‾‾‾‾‾│\n" \
    "│   \e[1m%02d\e[0m   │\n" \
    "│        │\n" \
    "│________│\n"

#define D4_ART \
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
	printf(D20_ART, value);
	printf(D12_ART, value);
	printf(D10_ART, value);
	printf(D8_ART, value);
	printf(D6_ART, value);
	printf(D4_ART, value);
}
