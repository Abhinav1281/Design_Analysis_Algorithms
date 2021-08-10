#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
int isPrimeNormal(int n) {
  int steps = 0; // loopStep=0,loopBStep=0;
  steps++;
  int div = 0;
  // loopStep++;

  for (int j = n; j >= 1; j--) {
    steps++;
    if (n % j == 0) {
      div++;
      steps++;
    }
    steps++;
  }
  steps++;
  if (div == 2) {
    // printf("%d\t",i);
    steps++;
  }

  // printf("\nLOOP RUNS=%d\nLOOP BODY RUNS=%d",loopStep,loopBStep);
  return steps;
}

int isPrimeHalf(int n) {
  int steps = 0;
  steps++;
  if ((n & 1) == 0) {
  } else {
    int div = 0;
    steps += 2;
    for (int i = 3; i < n; i += 2) {
      steps += 2;
      if (n % i == 0) {
        steps++;
        div++;
      }
    }
    steps++;
    if (div > 0) {
      // NOT PRIME
    } else {
      // PRIME
    }
  }
  return steps;
}

int isPrimeSieve(int n) {
  int steps = 0;
  steps++;
  bool ar[n + 1];
  steps++;
  ar[0] = false;
  ar[1] = false;
  steps += 2;
  for (int i = 2; i < n + 1; i++) {
    ar[i] = true;
    steps++;
  }
  steps++;
  for (int i = 2; i * i < n + 1; i++) {
    steps++;
    if (ar[i] == true) {
      steps++;
      for (int j = i * i; j < n + 1; j += i) {
        ar[j] = false;
        steps += 2;
      }
    }
    steps++;
  }
  steps++;
  if (ar[n] == true) {
    steps++;
    // printf("\nPRIME");
  }
  /*steps++;
  for(int i=2;i<n+1;i++)
  {
          steps+=2;
          if(ar[i]==true)
          {
                  steps++;
                  printf("%d\t",i);
          }
  }
  */
  return steps;
}

int main() {
  int valueAr[10][4];
  for (int i = 0; i < 10; i++) {
    printf("Enter value of n:");
    int n;
    scanf("%d", &n);
    valueAr[i][0] = n;
    valueAr[i][1] = isPrimeNormal(n);
    // printf("\nSTEPS FOR NORMAL=%d\n",x);
    valueAr[i][2] = isPrimeHalf(n);
    // printf("\nSTEPS FOR HALF=%d\n",x);
    valueAr[i][3] = isPrimeSieve(n);
    // printf("\nSTEPS FOR SIEVE=%d\n",x);
  }

  printf("\nSIZE\tALGO-1\tALGO-2\tALGO-3\n");
  for (int i = 0; i < 10; i++) {
    printf("\n%d\t%d\t%d\t%d\n", valueAr[i][0], valueAr[i][1], valueAr[i][2],
           valueAr[i][3]);
  }
}
