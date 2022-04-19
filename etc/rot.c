// rot-N shift. can do one wraparound
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if(argc!=3) {
    printf("usage: ./rot CHAR NUMBER\n works with lowercase alphabet (ascii 97-122).\n NUMBER can be negative. only one wraparound is implemented currently.\n");
    exit(1);
  }

  char c = argv[1][0];
  int ascval = (int) c;
  printf("%s - %d\n", argv[1], ascval);

  int offset = atoi(argv[2]);
  int newval = ascval+offset;

  if(newval>122) {
    newval = 97+(newval-122)-1;
  } else if (newval<97) {
    newval = 122-(abs(offset)-(ascval-97))+1;
  }

  printf("%c - %d\n", (char) newval, newval);
  return 0;
}
