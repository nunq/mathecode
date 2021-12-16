#include <stdio.h>
#include <math.h>

int main() {
  double res=0;
  for (int j=1;j<15;j++) { //change this
    res+=(1/(4*pow(j,2)-1)); //change this
    printf("%f\n",res);
  }
  printf("%f\n",res);

  return 0;
}
