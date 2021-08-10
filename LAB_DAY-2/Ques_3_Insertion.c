#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Abhinav Sinha
1929068
*/
int choiceMaker() {
  int ch;
  printf(
      "\n0. Quit\n1. n Random numbers=>Array\n2. Display the Array\n3. Sort "
      "the "
      "Array in Ascending Order by using Insertion Sort Algorithm\n4. Sort the "
      "Array in Descending Order by using any sorting algorithm\n5. Time "
      "Complexity to sort ascending of random data\n6. Time Complexity to sort "
      "ascending of data already sorted in ascending order\n7. Time Complexity "
      "to sort ascending of data already sorted in descending order\n8. Time "
      "Complexity to sort ascending of data for all Cases (DataAscending, Data "
      "in Descending & Random Data) in Tabular form for values n=5000 to "
      "50000, step=5000\n\nEnter Choice:");

  scanf("%d", &ch);
  return ch;
}
void printArray(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d\t", *(arr + i));
  }
}
long InsertionSort(int *arr, int n) {
  int cVal, j;
  long steps = 0;
  steps++;
  for (int i = 0; i < n; i++) {
    cVal = *(arr + i);
    j = i - 1;
    steps += 3;
    while (j >= 0 && *(arr + j) > cVal) {
      *(arr + j + 1) = *(arr + j);
      j -= 1;
      steps += 3;
    }
    *(arr + j + 1) = cVal;
    steps += 2;
  }
  return steps;
}
void RevSort(int *arr, int n) {
  int cVal, j;
  for (int i = 0; i < n; i++) {
    cVal = *(arr + i);
    j = i - 1;
    while (j >= 0 && *(arr + j) < cVal) {
      *(arr + j + 1) = *(arr + j);
      j -= 1;
    }
    *(arr + j + 1) = cVal;
  }
}
void HeavyData() {
  long arr[10][4];
  for (int i = 0; i < 10; i++) {
    int val = 5000 + (i * 5000);
    arr[i][0] = val;
    int *array = (int *)malloc(val * (sizeof(int)));
    for (int i = 0; i < val; i++)
      *(array + i) = rand() % val;
    arr[i][1] = InsertionSort(array, val);

    arr[i][2] = InsertionSort(array, val);
    RevSort(array, val);
    arr[i][3] = InsertionSort(array, val);
  }
  printf("\nValue\tSort Array\tAlready Sorted\tReversed Sorted\n");
  for (int i = 0; i < 10; i++) {
    printf("%ld\t%ld\t%ld\t%ld\n", arr[i][0], arr[i][1], arr[i][2], arr[i][3]);
  }
}
int main() {
  int n;
  int *arr;
  int timeAsort, timeAAsort, timeDsort;
  int ch = choiceMaker();
  while (ch != 0) {
    switch (ch) {
    case 1:
      printf("Enter Value of n:");
      scanf("%d", &n);
      arr = (int *)malloc(n * sizeof(int));
      for (int i = 0; i < n; i++) {
        *(arr + i) = rand() % n;
      }
      break;
    case 2:
      printArray(arr, n);
      break;
    case 3:
      InsertionSort(arr, n);
      break;
    case 4:
      RevSort(arr, n);
      break;
    case 5:

      timeAsort = InsertionSort(arr, n);

      printf("\nTime Taken to sort data:%d\n", timeAsort);
      break;
    case 6:
      InsertionSort(arr, n);

      timeAAsort = InsertionSort(arr, n);

      printf("\nTime Taken to sort already sorted data:%d\n", timeAAsort);
      break;
    case 7:
      RevSort(arr, n);
      timeDsort = InsertionSort(arr, n);

      printf("\nTime Taken to sort already Reveserly sorted data:%d\n",
             timeDsort);
      break;
    case 8:
      HeavyData();
      break;
    default:
      printf("WRONG CHOICE");
      break;
    }
    ch = choiceMaker();
  }
}