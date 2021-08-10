#include <stdio.h>
#include <stdlib.h>
/*
Abhinav Sinha
1929068
*/

int main() {
  int n;
  printf("Enter the number:");
  scanf("%d", &n);
  int i = 1;
  for (i = 1; (i * i) <= n; i++)
    ;
  printf("SQRT of %d is %d\n", n, i - 1);
}
