#include <stdio.h>
#include <stdlib.h>

int Euclid(int a, int b, int steps) {
  steps += 2;
  if (a == 0) {
    // printf("\n\t-->%d\n", b);
    return steps;
  }
  return Euclid(b % a, a, steps);
}
int ConseInt(int a, int b) {
  int steps = 1;
  int min = a <= b ? a : b;

  steps++;
  while (min != 1) {
    steps++;
    if (a % min == 0) {
      steps++;
      if (b % min == 0) {
        // printf("\t-->%d\n", min);
        return min;
      }
      steps++;
      min -= 1;
    } else
      min -= 1;
    steps++;
  }
  // printf("\t-->%d\n", min);
  return steps;
}
int MidGCD(int a, int b) {

  int steps = 1;
  int size = a >= b ? b : a + 1;
  int ara[size];
  int arb[size];
  steps++;
  for (int i = 0; i < size; i++) {
    ara[i] = 0;
    arb[i] = 0;
    steps += 3;
  }
  steps++;
  for (int i = 2; i < size;) {
    steps++;
    if (a % i == 0) {
      ara[i] += 1;
      a /= i;
      steps + 2;
      continue;
    } else
      i++;
    steps++;
  }
  steps++;
  for (int i = 2; i < size;) {
    steps++;
    if (b % i == 0) {
      steps += 2;
      arb[i] += 1;
      b /= i;
      continue;
    } else
      i++;
    steps++;
  }
  int gcd = 1;
  steps += 2;
  for (int i = 2; i < size; i++) {
    steps++;
    if (ara[i] != 0 && arb[i] != 0) {
      steps++;
      gcd *= (ara[i] <= arb[i] ? ara[i] : arb[i]) * i;
    }
    steps++;
  }
  // printf("\t-->%d\n", gcd);
  return steps;
}
int main() {
  int a[] = {31415, 56, 34218, 12, 31415, 12};
  int b[] = {14142, 32566, 56, 15, 31415, 12};
  int n[6][3];
  for (int i = 0; i < 6; i++) {
    n[i][0] = Euclid(a[i], b[i], 0);
    n[i][1] = ConseInt(a[i], b[i]);
    n[i][2] = MidGCD(a[i], b[i]);
  }
  printf("\nSL.\tEUCLID\tCIT\tMID\tVALUES\n");
  for (int i = 0; i < 6; i++) {
    printf("%d\t%d\t%d\t%d\t%d..%d\n", (i + 1), n[i][0], n[i][1], n[i][2], a[i],
           b[i]);
  }
}
