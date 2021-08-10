#include <stdio.h>
#include <stdlib.h>
/*
Abhinav Sinha
1929068
*/

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

int main() {
  int a, b, c;
  printf("Enter values:\na:");
  scanf("%d", &a);
  printf("b:");
  scanf("%d", &b);
  printf("c:");
  scanf("%d", &c);

  printf("\nBefore Swap:\na:%d\nb:%d\nc:%d", a, b, c);
  swap(&a, &b);
  swap(&a, &c);

  printf("\nAfter Swap:\na:%d\nb:%d\nc:%d", a, b, c);
}
