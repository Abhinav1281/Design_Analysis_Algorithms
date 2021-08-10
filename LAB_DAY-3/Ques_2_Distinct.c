#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void compareAr(int *arnew, int ar[], int n) {
  for (int i = 0; i < n; i++)
    if (*(arnew + i) >= n / 2)
      printf("\n%d::%d", i, *(arnew + i));
}
void checkwithspace(int arnew[], int ar[], int n) {
  printf("\nCHECKING WITH SPACE");
  for (int i = 0; i < n; i++)
    arnew[i] = 0;
  for (int i = 0; i < n; i++) {
    arnew[ar[i]]++;
  }
  // return arnew;
  compareAr(arnew, ar, n);
}

void moore(int ar[], int n) {
  int m = ar[0];
  int c = 1;
  for (int i = 0; i < n; i++) {
    if (m == ar[i])
      c++;
    else
      c--;
    if (c == 0)
      m = ar[i];
  }
  c = 0;
  for (int i = 0; i < n; i++) {
    if (m == ar[i])
      c++;
  }
  printf("%d occurs maximum times by %d times", m, c);
}
void printAr(int *ar, int n) {
  for (int i = 0; i < n; i++)
    printf("%d\t", *(ar + i));
}

void sort(int arr[], int n) {
  int cVal, j;
  for (int i = 0; i < n; i++) {
    cVal = *(arr + i);
    j = i - 1;
    while (j >= 0 && *(arr + j) > cVal) {
      *(arr + j + 1) = *(arr + j);
      j -= 1;
    }
    *(arr + j + 1) = cVal;
  }
}
int main() {
  int n;
  printf("Enter value of n:");
  scanf("%d", &n);
  int ar[n];
  for (int i = 0; i < n; i++)
    ar[i] = rand() % (n / 2);
  printAr(ar, n);
  int arnew[n];
  checkwithspace(arnew, ar, n);
  // checkwithoutspace(ar, n);
  moore(ar, n);
}