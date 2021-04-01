#include "public/std_c.h"

int clumsy(int N) {
  int op = 0, cur = N, len = N/2+1;
  int* stack = calloc(len, sizeof(int));
  memset(stack, 0, sizeof(int) * (len));
  int top = 0;
  stack[top++] = cur--;
  while (cur) {
    switch(op%4) {
      case 0: // multiply
      stack[top - 1] *= cur;
      break;
      case 1: // divide
      stack[top - 1] /= cur;
      break;
      case 2:
      stack[top++] = cur;
      break;
      case 3:
      stack[top++] = -cur;
      break;
    }
    cur--;
    op++;
  }
  int ret = 0;
  for (int i = top - 1; i >= 0; i--) {
    ret += stack[i];
  }
  free(stack);
  return ret;
} 

int main() {
  printf("%d\n", clumsy(10000));
}