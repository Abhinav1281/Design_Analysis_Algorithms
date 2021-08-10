#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InsertionSort(int *arr, int n) {
  int cVal, j;

  for (int i = 1; i < n; i++) {
    cVal = *(arr + i);
    j = i - 1;
    while (j >= 0 && *(arr + j) > cVal) {
      *(arr + j + 1) = *(arr + j);
      j -= 1;
    }
    *(arr + j + 1) = cVal;
  }
}
void printArray(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d\t", *(arr + i));
  }
}

int main() {
  int n;
  printf("Enter number of value:");
  scanf("%d", &n);
  int *arr = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    *(arr + i) = rand() % n;
  printf("\n");
  printArray(arr, n);
  InsertionSort(arr, n);
  printf("\n");
  printArray(arr, n);
}