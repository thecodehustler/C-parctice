#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int calculator(const char* expression) {
    const int len = strlen(expression);
    printf("Length: %d\n", len);
    int* numbers = (int*)malloc(len * sizeof(int));
    int pointer = 0;
    char lastOp = '+';
    memset(numbers, 0, len * sizeof(int));

    int num = 0;

    for (int i = 0; i < len; i++) {
        const char ch = expression[i];
        printf("%c\t", ch);
        if (ch >= '0') {
            num = num * 10 + (ch - '0');
        }
        if ((ch < '0' && ch != ' ') || i == len - 1) {
            switch (lastOp) {
                case '+':
                    numbers[pointer++] = num;
                    break;
                case '-':
                    numbers[pointer++] = -num;
                    break;
                case '*':
                    numbers[pointer - 1] *= num;
                    break;
                case '/':
                    numbers[pointer - 1] /= num;
                    break;
            }

            lastOp = ch;
            num = 0;
        }
    }
    int result = 0;
    for (int j = 0; j < pointer; j++) {
        result += numbers[j];
    }
    free(numbers);
    return result;
}

int main() {
    printf("%d\n", calculator("-3+2/2"));
    return 0;
}