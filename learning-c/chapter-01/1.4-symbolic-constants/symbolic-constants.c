/* Symbolic Constants */
#include <stdio.h>

#define LOWER 0    // lower limit of table
#define UPPER 300  // upper limit
#define STEP 20    // step size

int main(void){
  int fahr;

  for(fahr = LOWER; fahr <= 300; fahr = fahr + STEP)
    printf("%3d %6.2f\n", fahr, (5.0/9.0) * (fahr - 32));

  return 0;
}
