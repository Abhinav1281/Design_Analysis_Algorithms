#include <stdio.h>
#include <stdlib.h>

/*
Abhinav Sinha
1929068
*/

struct value {
  int val;
  int count;
  struct value *next;
};
int checkExist(struct value *x, int y) {
  int i = 0;
  while (x != NULL) {
    if (x->val == y)
      return i;
    x = x->next;
    i++;
  }
  return -1;
}
void incrCount(int n, struct value *x) {
  for (int i = 0; i < n; i++)
    x = x->next;
  // printf("\nCOUNT INCR:%d",x->val);
  x->count++;
}
void totalDup(struct value *x) {
  int total = 0, max = 0, maxNum = 0;
  while (x != NULL) {
    int ccount = x->count;
    if (ccount > max) {
      maxNum = x->val;
      max = ccount;
    }
    total += ccount - 1;
    x = x->next;
  }
  printf("\nMaximum Duplicates--\n%d has %d duplicates", maxNum, max - 1);
  printf("\nTotal Duplicates:%d", total);
}
void printValues(struct value *x) {
  while (x != NULL) {
    printf("\n%d:%d", x->val, x->count);
    x = x->next;
  }
};
int main() {
  int n;
  printf("Enter total values:");
  scanf("%d", &n);
  struct value *start = (struct value *)malloc(sizeof(struct value));
  // printf("Enter values:\n1:");
  // scanf("%d",&(start->val));
  int t = rand() % (n / 2 + n / 4);
  start->val = t;
  start->count = 1;
  start->next = NULL;
  printf("%d\t", t);
  struct value *current = start;
  for (int i = 1; i < n; i++) {
    int temp = rand() % (n / 2 + n / 4);
    // printf("\n%d:",(i+1));
    // scanf("%d",&temp);
    printf("%d\t", temp);
    int exist = checkExist(start, temp);
    if (exist > -1)
      incrCount(exist, start);
    else {
      struct value *node = (struct value *)malloc(sizeof(struct value));
      node->val = temp;
      node->count = 1;
      node->next = NULL;
      current->next = node;
      current = node;
    }
  }
  printValues(start);
  totalDup(start);
}
