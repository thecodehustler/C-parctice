#include <stdio.h>
#include <malloc.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
  int totalNumberSize = 0;
  for (int i = 0; i < matrixSize; i++) {
    totalNumberSize += matrixColSize[i];
  }
  int* ret = calloc(totalNumberSize, sizeof(int));
  // To be filled...
}

int main() {
  return 0;
}