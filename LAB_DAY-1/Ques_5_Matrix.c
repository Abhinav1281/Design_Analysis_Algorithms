#include <stdio.h>
#include <stdlib.h>
/*
Abhinav Sinha
1929068
*/

int main() {
  int n;
  printf("Enter size of matrix:");
  scanf("%d", &n);
  int ar[n][n];
  int lDiag = 0, mDiag = 0, nZ = 0, dSum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ar[i][j] = rand() % (n * n);
    }
  }
  printf("\nMATRIX GENERATED AS FOLLOWS:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("\t%d", ar[i][j]);
      if (ar[i][j] != 0)
        nZ++;
      if (i <= j)
        lDiag += ar[i][j];
      if ((n - i - 1) <= j)
        mDiag += ar[i][j];
      if (i == j || (n - i - 1) == j)
        dSum += ar[i][j];
    }
    printf("\n");
  }
  printf("\nNon-Zero Elements=%d\nAbove Leading Diagonal sum=%d\nBelow Minor "
         "Diagonal Sum=%d\nDiagonal Sum=%d\n",
         nZ, lDiag, mDiag, dSum);
}
