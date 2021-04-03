#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
  //
  bool flgCol = false, flgRow = false;

  for (int i = 0; i < matrixSize; i++) {
    if (!matrix[i][0]) {
      flgCol = true;
      break;
    }
  }

  for (int i = 0; i < *matrixColSize; i++) {
    if (!matrix[0][i]) {
      flgRow = true;
      break;
    }
  }

  // 标记本行、列要置 0；
  for (int i = 1; i < matrixSize; i++) {
    for (int j = 1; j < matrixColSize[i]; j++) {
      if (!matrix[i][j]) {
        matrix[i][0] = 0;
        matrix[0][j] = 0;
      }
    }
  }

  // 对非首行首列元素置 0；
  for (int i = 1; i < matrixSize; i++) {
    if (!matrix[i][0]) {
      for (int j = 1; j < matrixColSize[i]; j++) {
        matrix[i][j] = 0;
      }
    }
  }

  for (int j = 1; j < *matrixColSize; j++) {
    if (!matrix[0][j]) {
      for (int i = 1; i < matrixSize; i++) {
        matrix[i][j] = 0;
      }
    }
  }

  if (flgRow) {
    for (int i = 0; i < *matrixColSize; i++) {
      matrix[0][i] = 0;
    }
  }
  if (flgCol) {
    for (int i = 0; i < matrixSize; i++) {
      matrix[i][0] = 0;
    }
  }
}

int main() {
  //
  int arr[3][4] = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  int sizes[] = {4, 4, 4};
  int** p = arr;
  setZeroes(p, 3, sizes);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d\t", arr[i][j]);
    }
    putchar('\n');
  }
  return 0;
}