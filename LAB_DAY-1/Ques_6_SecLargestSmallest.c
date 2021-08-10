#include <stdio.h>
#include <stdlib.h>
/*
Abhinav Sinha
1929068
*/

void printArray(int *ar, int n) {
  printf("\nArray is:\n");
  for (int i = 0; i < n; i++)
    printf("%d\t", *(ar + i));
}
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void sort(int *ar, int n) {
  int *min;
  for (int i = 0; i < n - 1; i++) {
    min = ar + i;
    for (int j = i + 1; j < n; j++) {
      if (*(ar + j) < *min)
        min = ar + j;
    }
    swap(ar + i, min);
  }
}
void SecValues(int *ar, int n) {
  printf("\nSecond Largest:%d", *(ar + (n - 2)));
  printf("\nSecond Smallest:%d", *(ar + 1));
}
int main() {
  int n;
  printf("Enter number of values:");
  scanf("%d", &n);
  int *ar = (int *)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++)
    *(ar + i) = rand() % n;
  printArray(ar, n);
  sort(ar, n);
  SecValues(ar, n);
}
