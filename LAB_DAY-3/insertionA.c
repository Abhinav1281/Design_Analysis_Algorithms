#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void insort(int arr[], int n) {
  int i, key, j;
  int *p = &arr[0];
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}
void revAr(int *x, int n) {
  int *start = x;
  int *end = x + n - 1;
  for (int i = 0; i < n / 2; i++, start++, end--)
    swap(start, end);
}
void printAr(int *x, int n) {
  for (int i = 0; i < n; i++)
    printf("%d\t", *(x + i));
}
int main() {
  int n;
  printf("Enter number of values:");
  scanf("%d", &n);
  int *p = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++)
    *(p + i) = rand() % n;

  //   printf("\nINITIAL ARRAY:\n");
  //   printAr(p, n);
  int beginT = clock();
  insort(p, n);
  int endT = clock();
  // printf("\nSORTED ARRAY\n");
  int SbeginT = clock();
  // printAr(p, n);
  insort(p, n);
  int SendT = clock();
  revAr(p, n);
  // printf("\nREVERSED ARRAY:\n");
  // printAr(p, n);
  int RbeginT = clock();
  insort(p, n);
  int RendT = clock();

  // printf("Begin Time:%d\nEnd Time:%d",SbeginT,SendT);
  printf("\nTotal Time:%d", (endT - beginT));
  printf("\nTotal Sorted Time:%d", (SendT - SbeginT));
  printf("\nTotal Reverse Time:%d", (RendT - RbeginT));
}