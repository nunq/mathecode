#include <stdio.h>
#include <math.h>

#define MAX 1000

int main() {
  for(double m=0;m<=MAX;m++) {
    for(double n=0;n<=MAX;n++) {
      if((pow(m,2)+8) == pow(3,n)) {
        printf("%.0f, %.0f\n", m, n);
      }
    }
  }
}