#include <stdio.h>
#include <stdlib.h>
/*
Abhinav Sinha
1929068
*/

int main() {
  int a, b;
  printf("Enter values:");
  scanf("%d%d", &a, &b);

  int max = ((a + b) + (abs(a - b))) / 2;
  printf("\nMAX:%d\n", max);
}
