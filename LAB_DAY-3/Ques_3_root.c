#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int squaret(int i, int n) {
  // printf("\n%d", i);
  if (i * i >= n)
    return i;
  else
    return squaret(i + 1, n);
}
int main() {
  int n;
  printf("Enter value of n:");
  scanf("%d", &n);
  int root = squaret(1, n);
  printf("\nRoot of %d is %d", n, root);
}