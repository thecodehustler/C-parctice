#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>

#include "public/arr_alloc.h"

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize,
                  int target) {
    int curr = 0, low = 0, high = matrixSize * (*matrixColSize);
    while (low <= high) {
        curr = low + (high - low) / 2;
        int num = matrix[curr / (*matrixColSize)][curr % (*matrixColSize)];
        if (target == num) {
            return true;
        } else if (target > num) {
            low = curr + 1;
        } else {
            high = curr - 1;
        }
    }
    return false;
}

int main() {
    int a[] = {1, 3};
    int** arr = arr_alloc(a, 1, 2);
    int len[] = {2};
    printf("%d\n", searchMatrix(arr, 1, len, 3));
}