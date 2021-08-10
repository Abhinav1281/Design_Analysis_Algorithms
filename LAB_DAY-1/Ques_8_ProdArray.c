#include <stdio.h>
#include <stdlib.h>
/*
Abhinav Sinha
1929068
*/

void printArray(int ar[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d\t", ar[i]);
}

int main() {
  int n, prod = 1;
  printf("Enter size of array:");
  scanf("%d", &n);
  int ar[n];
  int outar[n];
  for (int i = 0; i < n; i++) {
    ar[i] = 1 + rand() % n;
    prod *= ar[i];
    // printf("%d\t",ar[i]);
  }
  printf("\nINPUT ARRAY:\n");
  printArray(ar, n);
  for (int i = 0; i < n; i++)
    outar[i] = (int)prod / ar[i];

  printf("\nOUTPUT ARRAY:\n");
  printArray(outar, n);
}
