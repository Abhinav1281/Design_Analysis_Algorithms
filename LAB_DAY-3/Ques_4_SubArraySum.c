#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// int sumAr(int ar[], int a, int b) {
//   int sum = 0;
//   for (int i = a; i <= b; i++)
//     sum += ar[i];
//   return sum;
// }

// int calcsum(int ar[], int n) {
//   int sumar[n][n];
//   int max = 0, maxi = -1, maxj = -1;
//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < n; j++) {
//       sumar[i][j] = sumAr(ar, i, j);
//       if (max < sumar[i][j]) {
//         max = sumar[i][j];
//         maxi = i;
//         maxj = j;
//       }
//     }
//   }
//   printf("%d is the maximum sum for the subarray %d to %d", max, maxi, maxj);
// }
int max(int a, int b) { return a > b ? a : b; }
void kdne(int ar[], int n) {
  int sum = INT_MIN;
  for (int i = 0; i < n;) {
    int c_sum = max(c_sum, c_sum + ar[i++]);
    sum = max(sum, c_sum);
  }
  printf("Maximum subarray sum=%d", sum);
}
int main() {
  int n;
  printf("Enter size of array:");
  scanf("%d", &n);
  int ar[n];
  printf("Enter array elements:\n");
  for (int i = 0; i < n; i++)
    scanf("%d", &(ar[i]));
  // calcsum(ar, n);
  kdne(ar, n);
}