// zwischen 0 und 1.000.000.000, die genau n Teiler haben, dauert sehr lange da single-threaded
// gcc -W -o nteiler nteiler.c
#include <stdio.h>

int main() {
  unsigned long num = 50000;
  unsigned long result = 0; // 1 und N auf ergebnis addieren
  int nteiler = 20;
  for (unsigned int i=nteiler; i<=num; i++) { // erst bei nteiler anfangen
  int count = 2; // 1 und num sind schon teiler
  //printf("checking: %d\n", i);
    for (unsigned int j=2; j<i; j++) {
      if (count > nteiler) {
        continue;
      }
    //printf("against: %d\n", j);
      if (i % j == 0) {
        //printf("OK: %d\n", i);
        count+=1;
      }
    }
    if (count == nteiler) {
      printf("FOUND: %d\n", i);
      result += i;
    }
  }
  printf("%ld\n", result);
  printf("%lx\n", result);
}
