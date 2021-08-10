#include <stdio.h>
#include <stdlib.h>
/*
Abhinav Sinha
1929068
*/

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void printArray(int *ar, int n) {
  for (int i = 0; i < n; i++)
    printf("%d\t", *(ar + i));
}

int main() {
  int n;
  printf("Enter number of values:");
  scanf("%d", &n);
  int ar[n];
  for (int i = 0; i < n; i++)
    ar[i] = rand() % n;
  printf("\nBefore Swapping:\n");
  printArray(&ar, n);
  int loopVar = ((n & 1) == 1) ? n - 1 : n;
  for (int i = 0; i < loopVar; i += 2)
    swap(&ar[i], &ar[i + 1]);

  printf("\nAfter Swapping:\n");
  printArray(&ar, n);
}
