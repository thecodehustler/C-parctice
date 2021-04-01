#include <malloc.h>
#include <stdio.h>

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
  int** matrix = calloc(n, sizeof(int*));
  int* columnSizes = calloc(n, sizeof(int));
  for (int i = 0; i < n; i++) {
    columnSizes[i] = n;
    matrix[i] = calloc(n, sizeof(int));
  }
  *returnSize = n;

  //
  const int upperLimit = n * n;
  int top = -1, bottom = n, left = -1, right = n;
  int direction = 0;
  int nextX = 0, nextY = 0;
  for (int i = 1; i <= upperLimit; i++) {
    //
    matrix[nextY][nextX] = i;
    int x = nextX, y = nextY;
    attempt: {
      nextX = x; nextY = y;
      switch (direction % 4) {
        case 0: // Right
          nextX = x + 1;
          if (nextX == right) {
            direction++;
            top += 1;
            goto attempt;
          }
          break;
        case 1: // Down
          nextY = y + 1;
          if (nextY == bottom) {
            direction++;
            right -= 1;
            goto attempt;
          }
          break;
        case 2: // Left
          nextX = x - 1;
          if (nextX == left) {
            direction ++;
            bottom -= 1;
            goto attempt;
          }
          break;
        case 3: // Up
          nextY = y - 1;
          if (nextY == top) {
            direction ++;
            left += 1;
            goto attempt;
          }
          break;
      }
    }
  }
  //
  return matrix;
}

/* 无助又卑微的 main 函数 */
int main() {
  int* retColumnSizes = 0;
  int size = 0;
  const int n = 1;
  int** matrix = generateMatrix(n, &size, &retColumnSizes);
  printf("Stop!\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  for (int i = 0; i < size; i++) {
    free(matrix[i]);
  }
  free(matrix);
  free(retColumnSizes);
  return 0;
}