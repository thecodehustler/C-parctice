#include <malloc.h>
#include <stdio.h>

int *spiralOrder(int **matrix, int matrixSize, int *matrixColSize,
                 int *returnSize) {
    printf("%d ", matrixSize);
    int *pSize = (int *)malloc(sizeof(int));
    *pSize = 0;  // C 语言对于分配的堆内存不会给你初始化。

    for (int i = 0; i < matrixSize; i++) {
        *pSize += matrixColSize[i];
    }
    *returnSize = *pSize;

    printf("%d", *pSize);

    int scopeLeft = -1, scopeRight = matrixColSize[0], scopeTop = -1,
        scopeBottom = matrixSize;
    int *ret = calloc(*pSize, sizeof(int));

    int nextX = 0, nextY = 0;
    int direction =
        0;  // Right = 0; Down = 1; Left = 2; Up = 3; 取 direction % 4

    for (int i = 0; i < *pSize; i++) {
        ret[i] = matrix[nextX][nextY];
        int currX = nextX, currY = nextY;
        do {
            nextX = currX;
            nextY = currY;
            switch (direction % 4) {
                case 0:
                    nextX += 1;
                    break;
                case 1:
                    nextY += 1;
                    break;
                case 2:
                    nextX -= 1;
                    break;
                case 3:
                    nextY -= 1;
                    break;
            }
            if (nextX <= scopeLeft || nextX >= scopeRight ||
                nextY <= scopeTop || nextY >= scopeBottom) {
                direction++;
                if (nextX <= scopeLeft) {
                    scopeBottom -= 1;
                    break;
                } else if (nextX >= scopeRight) {
                    scopeTop += 1;
                    break;
                }
                if (nextY <= scopeTop) {
                    scopeLeft += 1;
                    break;
                } else if (nextY >= scopeBottom) {
                    scopeRight -= 1;
                    break;
                }
            } else {
                break;
            }

        } while (1);
    }

    return ret;
}