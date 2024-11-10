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


int dice[6] = {20, 12, 10, 8, 6, 4};

int get_random(int size) {
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
  int closest_die = dice[0];
  for(i=0;i<6;i++){
    if(absdiff[i] < min){
      min = absdiff[i];
      closest_die = dice[i];
    }
  }
  return closest_die;
}

char* get_art_const(int size) {
  switch(size){
    case 20: return D20_ART;
    case 12: return D12_ART;
    case 10: return D10_ART;
    case 8: return D8_ART;
    case 6: return D6_ART;
    case 4: return D4_ART;
    default: return "if your seeing this something went wrong, uhh anyway heres your number: \e[1m%02d\e[0m\n";
  }
}

void get_art(int size, char* buffer, size_t buffer_size, int value){
  snprintf(buffer, buffer_size, get_art_const(size), value);
}

void print_die(int size, int value){
  char buffer[234]; // smallest value that works. dont ask how i know :')
  get_art(size, buffer, sizeof(buffer), value);
  printf("%s", buffer);
}

void roll(int size, int count){
  int i = count;
  for(;i>0;i--){
    print_die(get_closest(size), get_random(size));
  }
}

int main(int argc, char* argv[]) {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	long milliseconds = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	srand(milliseconds);

  roll(21,1);
}
