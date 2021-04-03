#include <malloc.h>

int** arr_alloc(int* arr, int row, int col) {
  int** ret = (int**)calloc(row, sizeof(int*));
  for (int i = 0; i < row; i++) {
    ret[i] = calloc(col, sizeof(int));
    for (int j = 0; j < 4; j++) {
      ret[i][j] = *((arr+i*col)+j);
    }
  }
  return ret;
}