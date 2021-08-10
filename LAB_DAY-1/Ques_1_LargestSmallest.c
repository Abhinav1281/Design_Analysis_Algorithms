#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/*
Abhinav Sinha
1929068
*/

int main() {
  int n;
  printf("Enter total numbers:");
  scanf("%d", &n);
  int ar[n];
  int largest = INT_MIN;
  int smallest = INT_MAX;
  for (int i = 0; i < n; i++) {
    // printf("Enter value:");
    // scanf("%d",&ar[i]);
    ar[i] = rand() % n;
    if (ar[i] < smallest)
      smallest = ar[i];
    if (ar[i] > largest)
      largest = ar[i];
  }
  printf("\n");
  for (int i = 0; i < n; i++)
    printf("%d\t", ar[i]);
  printf("\nLARGEST=%d\nSMALLEST=%d", largest, smallest);
}
