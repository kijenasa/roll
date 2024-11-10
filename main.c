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

#define GET_ART(size) D##size##_ART //TODO: make this work idk >_>

int dice[6] = {20, 12, 10, 8, 6, 4};

int roll(int size) {
	int num = (rand() % size) + 1;
	return num;
}

int get_closest(int size) {
  int i;
  int absdiff[6];
  for(i=0;i<6;i++) {
    absdiff[i] = abs(dice[i] - size);
  }
  int min = absdiff[0];
  int closest_die;
  for(i=0;i<6;i++){
    if(absdiff[i] < min){
      min = absdiff[i];
      closest_die = dice[i];
    }
  }
  return closest_die;
}

void print_die(int size){
  printf("%s\n", GET_ART(size));
}

int main(int argc, char* argv[]) {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	long milliseconds = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	srand(milliseconds);

	int value = roll(20);
  print_die(20);
}
