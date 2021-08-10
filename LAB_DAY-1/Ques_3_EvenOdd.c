#include <stdio.h>
#include <stdlib.h>
/*
Abhinav Sinha
1929068
*/

struct value {
  int val;
  struct value *next;
};
void addVal(struct value *x, int v) {
  while (x->next != NULL)
    x = x->next;
  struct value *node = (struct value *)malloc(sizeof(struct value));
  node->val = v;
  node->next = NULL;
  x->next = node;
}

int main() {
  struct value *even = (struct value *)malloc(sizeof(struct value));
  struct value *odd = (struct value *)malloc(sizeof(struct value));
  even->val = 222;
  even->next = NULL;
  odd->val = 111;
  odd->next = NULL;
  printf("Enter values(0 to stop entering):\n");
  int temp = 2;
  while (temp > 0) {
    temp;
    scanf("%d", &temp);
    if (temp == 0)
      break;
    if ((temp & 1) == 1)
      addVal(odd, temp);
    else
      addVal(even, temp);
  }
  even = even->next;
  odd = odd->next;
  struct value *final = even;
  while (even->next != NULL)
    even = even->next;
  even->next = odd;
  while (final != NULL) {
    printf("%d::", final->val);
    final = final->next;
  }
}
